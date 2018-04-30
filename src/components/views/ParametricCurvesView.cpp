#include "ParametricCurvesView.h"

Components::Views::ParametricCurves::ParametricCurves(Components::ParametricCurves * p): Base(p->name), parametricCurves(p) {
    if(!p) return;
    vector<std::string> data;
    data.push_back("Bezier");
    data.push_back("Catmull-rom");
    this->switchView = Components::Views::Generator::switchView("Curve type: ", data, 0);
    this->colorView = Components::Views::Generator::color("Color: ", &this->parametricCurves->color);
    this->widthView = Components::Views::Generator::numeric("Line width: ", this->parametricCurves->getWidth());
    this->pointCount = Components::Views::Generator::numeric("Control point count: ", this->parametricCurves->getPointSize());
    this->widthView->valueLabel->tag = 0;
    ofAddListener(this->widthView->valueLabel->onclick, this, &Components::Views::ParametricCurves::click);
    ofAddListener(this->widthView->valueLabel->onrightclick, this, &Components::Views::ParametricCurves::rightclick);
    this->pointCount->valueLabel->tag = 1;
    ofAddListener(this->pointCount->valueLabel->onclick, this, &Components::Views::ParametricCurves::click);
    ofAddListener(this->pointCount->valueLabel->onrightclick, this, &Components::Views::ParametricCurves::rightclick);
    this->switchView->valueLabel->tag = 2;
    ofAddListener(this->switchView->valueLabel->onclick, this, &Components::Views::ParametricCurves::click);
    ofAddListener(this->switchView->valueLabel->onrightclick, this, &Components::Views::ParametricCurves::rightclick);

    this->contentView->addSubview(this->switchView);
    this->contentView->addSubview(this->colorView);
    this->contentView->addSubview(this->widthView);
    this->contentView->addSubview(this->pointCount);

    for(int i = 0; i < this->parametricCurves->getPointSize(); ++i) {
        ofVec3f v = this->parametricCurves->getPoint(i);
        this->points.push_back(Components::Views::Generator::vector3("Point " + std::to_string(i), Vector3(v.x, v.y, 0)));
        //Z is ignored
        for(int j = 0; j < 2; ++j) {
            this->points[i]->valueLabels[j]->tag = i * 2 + j + 4;
            ofAddListener(this->points[i]->valueLabels[j]->onclick, this, &Components::Views::ParametricCurves::click);
            ofAddListener(this->points[i]->valueLabels[j]->onrightclick, this, &Components::Views::ParametricCurves::rightclick);
        }
        this->contentView->addSubview(this->points[i]);
    }
}

Components::Views::ParametricCurves::~ParametricCurves() {
    ofRemoveListener(this->switchView->valueLabel->onclick, this, &Components::Views::ParametricCurves::click);
    ofRemoveListener(this->switchView->valueLabel->onrightclick, this, &Components::Views::ParametricCurves::rightclick);
    ofRemoveListener(this->widthView->valueLabel->onclick, this, &Components::Views::ParametricCurves::click);
    ofRemoveListener(this->widthView->valueLabel->onrightclick, this, &Components::Views::ParametricCurves::rightclick);
    ofRemoveListener(this->pointCount->valueLabel->onclick, this, &Components::Views::ParametricCurves::click);
    ofRemoveListener(this->pointCount->valueLabel->onrightclick, this, &Components::Views::ParametricCurves::rightclick);

    for(int i = 0; i < this->points.size(); ++i) {
        for(int j = 0; j < 2; ++j) {
            ofRemoveListener(this->points[i]->valueLabels[j]->onclick, this, &Components::Views::ParametricCurves::click);
            ofRemoveListener(this->points[i]->valueLabels[j]->onrightclick, this, &Components::Views::ParametricCurves::rightclick);
        }
    }
}

void Components::Views::ParametricCurves::layoutSubviews() {
    int x = 0;
    this->switchView->frame = UIKit::CGRect(0, x, this->frame.size.width, this->switchView->height);
    x += this->switchView->height;
    this->colorView->frame = UIKit::CGRect(0, x, this->frame.size.width, this->colorView->height);
    x += this->colorView->height;
    this->widthView->frame = UIKit::CGRect(0, x, this->frame.size.width, this->widthView->height);
    x += this->widthView->height;
    this->pointCount->frame = UIKit::CGRect(0, x, this->frame.size.width, this->pointCount->height);
    x += this->pointCount->height;
    for(int i = 0; i < this->points.size(); ++i) {
        this->points[i]->frame = UIKit::CGRect(0, x, this->frame.size.width, this->points[i]->height);
        x += this->points[i]->height;
    }

    this->contentView->frame = UIKit::CGRect(0, 0, this->frame.size.width, x);
    Components::Views::Base::layoutSubviews();
}

void Components::Views::ParametricCurves::setText(int tag) {
    switch(tag) {
        case 0: this->widthView->setValue(this->parametricCurves->getWidth());
        case 1: this->pointCount->setValue(this->parametricCurves->getPointSize());
        case 2: this->switchView->setValue(this->parametricCurves->getCurveType()); break;
        default:
            {
                int index = floor((tag - 4) / 2);
                if(index >= this->points.size()) { return; }
                ofVec3f v = this->parametricCurves->getPoint(index);
                this->points[index]->setValue(Vector3(v.x, v.y, 0));
            }
    }
}

void Components::Views::ParametricCurves::addPoint() {
    this->parametricCurves->setPointSize(this->parametricCurves->getPointSize() + 1);
    this->points.push_back(Components::Views::Generator::vector3("Point " + std::to_string(this->parametricCurves->getPointSize() - 1), Vector3()));
    for(int j = 0; j < 2; ++j) {
        this->points[this->points.size() - 1]->valueLabels[j]->tag = this->points.size() * 2 + j + 2;
        ofAddListener(this->points[this->points.size() - 1]->valueLabels[j]->onclick, this, &Components::Views::ParametricCurves::click);
        ofAddListener(this->points[this->points.size() - 1]->valueLabels[j]->onrightclick, this, &Components::Views::ParametricCurves::rightclick);
    }
    this->contentView->addSubview(this->points[this->points.size() - 1]);
    this->layoutSubviews();
}

void Components::Views::ParametricCurves::removePoint() {
    if(this->parametricCurves->getPointSize() > 4) {
        this->parametricCurves->setPointSize(this->parametricCurves->getPointSize() - 1);
        Components::Views::Vector3View* view = this->points[this->points.size() - 1];
        this->points.pop_back();
        for(int j = 0; j < 2; ++j) {
            view->valueLabels[j]->tag = this->points.size() * 2 + j + 2;
            ofRemoveListener(view->valueLabels[j]->onclick, this, &Components::Views::ParametricCurves::click);
            ofRemoveListener(view->valueLabels[j]->onrightclick, this, &Components::Views::ParametricCurves::rightclick);
        }
        this->contentView->removeSubview(view);
        delete view;
        this->layoutSubviews();
    }
}

void Components::Views::ParametricCurves::click(UIView & view) {
    switch(view.tag) {
        case 0: this->parametricCurves->setWidth(this->parametricCurves->getWidth() + 1); break;
        case 1: this->addPoint(); break;
        case 2:
            this->parametricCurves->setCurveType(
                (this->parametricCurves->getCurveType() == Components::curveTypes::Bezier ?
                 Components::curveTypes::CatmullRom : Components::curveTypes::Bezier));
            break;
        default: 
            {
                int index = floor((view.tag - 4) / 2);
                if(index >= this->points.size()) { return; }
                if(view.tag % 2 == 0) {
                    this->points[index]->setValue(Vector3(this->parametricCurves->getPoint(index).x + 5, this->parametricCurves->getPoint(index).y, 0));
                    this->parametricCurves->setPoint(index, ofVec3f(this->parametricCurves->getPoint(index).x + 5, this->parametricCurves->getPoint(index).y));
                } else {
                    this->points[index]->setValue(Vector3(this->parametricCurves->getPoint(index).x, this->parametricCurves->getPoint(index).y + 5, 0));
                    this->parametricCurves->setPoint(index, ofVec3f(this->parametricCurves->getPoint(index).x, this->parametricCurves->getPoint(index).y + 5));
                }
            }
    }
    this->setText(view.tag);
}

void Components::Views::ParametricCurves::rightclick(UIView & view) {
    switch(view.tag) {
        case 0: this->parametricCurves->setWidth(this->parametricCurves->getWidth() - 1); break;
        case 1: this->removePoint(); break;
        case 2: 
            this->parametricCurves->setCurveType(
                                                (this->parametricCurves->getCurveType() == Components::curveTypes::Bezier ?
                                                 Components::curveTypes::CatmullRom : Components::curveTypes::Bezier));
            break;
        default:
            {
                int index = floor((view.tag - 4) / 2);
                if(index >= this->points.size()) { return; }
                if(view.tag % 2 == 0) {
                    this->points[index]->setValue(Vector3(this->parametricCurves->getPoint(index).x - 5, this->parametricCurves->getPoint(index).y, 0));
                    this->parametricCurves->setPoint(index, ofVec3f(this->parametricCurves->getPoint(index).x - 5, this->parametricCurves->getPoint(index).y));
                } else {
                    this->points[index]->setValue(Vector3(this->parametricCurves->getPoint(index).x, this->parametricCurves->getPoint(index).y - 5, 0));
                    this->parametricCurves->setPoint(index, ofVec3f(this->parametricCurves->getPoint(index).x, this->parametricCurves->getPoint(index).y - 5));
                }
            }
    }
    this->setText(view.tag);
}
