#pragma once

#include "components/RenderableComponent.h"
#include <map>

namespace Components
{
    enum curveTypes {
        Bezier,
        CatmullRom
    };
    class ParametricCurves : public RenderableComponent {
        //General information
        float width = 2;
        unsigned int precisionCount = 30;
        ofPolyline line;
        vector<ofVec3f> points;
        curveTypes curveStyle = curveTypes::Bezier;

        //Bezier
        unsigned int permutation(unsigned int v);
        ofVec3f bezier(double t);
        void updateLine();

        //Catmull-Rom
        struct CubicPoly;
        struct Vec2D;
        vector<pair<CubicPoly, CubicPoly>> polys;
        void initCubicPoly(float x0, float x1, float t0, float t1, CubicPoly &p);
        void initNonuniformCatmullRom(float x0, float x1, float x2, float x3, float dt0, float dt1, float dt2, CubicPoly &p);
        void initCentripetalCR(const Vec2D& p0, const Vec2D& p1, const Vec2D& p2, const Vec2D& p3, const int index = 0);
        float vecDistSquared(const Vec2D& p, const Vec2D& q);
        void catmull();

        public:
        ParametricCurves();
        ofColor color = ofColor::white;

        void setPrecision(unsigned int value);
        unsigned int getPrecision();
        ofVec3f getPoint(unsigned int index);
        void setPoint(unsigned int index, ofVec3f value = ofVec3f());
        unsigned int getPointSize();
        void setPointSize(unsigned int value);
        void setWidth(float value);
        float getWidth();
        curveTypes getCurveType();
        void setCurveType(curveTypes value);

        ParametricCurves* createInstance() override { return new ParametricCurves(); }
        void render(bool useTexture) override;
        UIKit::UIView* getUIView() override;
        int getUIViewHeight() override;
    };
}
