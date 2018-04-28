#include "ParametricCurves.h"
#include "views/ParametricCurvesView.h"

unsigned int Components::ParametricCurves::permutation(unsigned int v) {
    unsigned int a = v;
    int i = v;
    while(--i > 0) {
        a *= i;
    }
    return a;
}

ofVec3f Components::ParametricCurves::bezier(double t) {
    if(this->points.size() != 0) {
        if(t == 0) { return this->points[0]; }
        else if(t == 1) { return this->points[this->points.size() - 1]; }
        else {
            ofVec3f point;

            double u = 1 - t;
            unsigned int n = this->points.size() - 1;
            unsigned int np = permutation(n);

            for(unsigned int k = 0; k < this->points.size(); ++k) {
                double v = (permutation(k)*permutation(n - k));
                double p = (v == 0 ? 1 : (np / v)) * std::pow(t, k) * std::pow(u, (n - k));
                point += ofVec3f(this->points[k].x * p, this->points[k].y * p, this->points[k].z * p);
            }
            return point;
        }
    } else { return ofVec3f(); }
}

void Components::ParametricCurves::updateLine() {
    switch(this->curveStyle) {
        case curveTypes::Bezier: 
            for(double i = 0; i <= this->precisionCount; ++i) {
                line[i] = this->bezier(i / (double)this->precisionCount);
            }
            break;
        case curveTypes::CatmullRom: this->catmull(); break;
    }
    
}

struct Components::ParametricCurves::CubicPoly {
    float c0, c1, c2, c3;

    float eval(float t) {
        float t2 = t * t;
        float t3 = t2 * t;
        return c0 + c1 * t + c2 * t2 + c3 * t3;
    }
};

struct Components::ParametricCurves::Vec2D {
    float x, y;
    Vec2D(float _x, float _y) : x(_x), y(_y) {}
};

void Components::ParametricCurves::initCubicPoly(float x0, float x1, float t0, float t1, CubicPoly & p) {
    p.c0 = x0;
    p.c1 = t0;
    p.c2 = -3 * x0 + 3 * x1 - 2 * t0 - t1;
    p.c3 = 2 * x0 - 2 * x1 + t0 + t1;
}

void Components::ParametricCurves::initNonuniformCatmullRom(float x0, float x1, float x2, float x3, float dt0, float dt1, float dt2, CubicPoly & p) {
    float t1 = (x1 - x0) / dt0 - (x2 - x0) / (dt0 + dt1) + (x2 - x1) / dt1;
    float t2 = (x2 - x1) / dt1 - (x3 - x1) / (dt1 + dt2) + (x3 - x2) / dt2;
    t1 *= dt1;
    t2 *= dt1;
    initCubicPoly(x1, x2, t1, t2, p);
}

void Components::ParametricCurves::initCentripetalCR(const Vec2D & p0, const Vec2D & p1, const Vec2D & p2, const Vec2D & p3, const int index) {
    float dt0 = powf(vecDistSquared(p0, p1), 0.25f);
    float dt1 = powf(vecDistSquared(p1, p2), 0.25f);
    float dt2 = powf(vecDistSquared(p2, p3), 0.25f);

    if(dt1 < 1e-4f)    dt1 = 1.0f;
    if(dt0 < 1e-4f)    dt0 = dt1;
    if(dt2 < 1e-4f)    dt2 = dt1;

    initNonuniformCatmullRom(p0.x, p1.x, p2.x, p3.x, dt0, dt1, dt2, polys[index].first);
    initNonuniformCatmullRom(p0.y, p1.y, p2.y, p3.y, dt0, dt1, dt2, polys[index].second);
}

float Components::ParametricCurves::vecDistSquared(const Vec2D & p, const Vec2D & q) {
    float dx = q.x - p.x;
    float dy = q.y - p.y;
    return dx * dx + dy * dy;
}

void Components::ParametricCurves::catmull() {
    if(this->points.size() >= 4) {
        polys.clear();
        line.clear();
        for(int i = 0; i <= points.size() - 4; ++i) {
            polys.resize(polys.size() + 1);
            initCentripetalCR(Vec2D(points[0 + i].x, points[0 + i].y), Vec2D(points[1 + i].x, points[1 + i].y), Vec2D(points[2 + i].x, points[2 + i].y), Vec2D(points[3 + i].x, points[3 + i].y), i);
        }
        for(int j = 0; j < polys.size(); ++j) {
            for(int i = 0; i <= this->precisionCount; ++i) {
                line.addVertex(polys[j].first.eval(i / (double)precisionCount), polys[j].second.eval(i / (double)precisionCount));
            }
        }
    }
}

Components::ParametricCurves::ParametricCurves() {
    this->name = "Parametric Curve";
    this->curveStyle = curveTypes::Bezier;
    this->points.resize(4);
    this->setPrecision(this->getPrecision());
}

void Components::ParametricCurves::setPrecision(unsigned int value) {
    this->precisionCount = value;
    line.clear();
    for(unsigned int i = 0; i <= value; ++i) {
        line.addVertex(ofVec3f());
    }
    this->updateLine();
}

unsigned int Components::ParametricCurves::getPrecision() {
    return this->precisionCount;
}

ofVec3f Components::ParametricCurves::getPoint(unsigned int index) {
    if(index < this->points.size()) { return this->points[index]; }
    else { return ofVec3f(); }
}

void Components::ParametricCurves::setPoint(unsigned int index, ofVec3f value) {
    if(index < this->points.size()) { this->points[index] = value; }
    this->updateLine();
}

unsigned int Components::ParametricCurves::getPointSize() {
    return this->points.size();
}

void Components::ParametricCurves::setPointSize(unsigned int value) {
    if(value >= 4) { this->points.resize(value); }
    this->updateLine();
}

void Components::ParametricCurves::setWidth(float value) {
    this->width = value;
}

float Components::ParametricCurves::getWidth() {
    return this->width;
}

Components::curveTypes Components::ParametricCurves::getCurveType() {
    return this->curveStyle;
}

void Components::ParametricCurves::setCurveType(Components::curveTypes value) {
    this->curveStyle = value;
    this->updateLine();
}

void Components::ParametricCurves::render(bool useTexture) {
    ofSetLineWidth(this->width);
    ofSetColor(this->color);
    this->line.draw();
}

UIKit::UIView * Components::ParametricCurves::getUIView() {
    return new Components::Views::ParametricCurves(this);
}

int Components::ParametricCurves::getUIViewHeight() {
    return 20 + 30 + 30 + 30 + 30 + 30 * this->points.size();
}
