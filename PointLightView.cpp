#include "src\components\views\PointLightView.h"

Components::Views::PointLight::PointLight(Components::PointLight * pointLight) : Base(pointLight->name), pointLight(pointLight) {
    if(!pointLight) return;
    this->colorView = Components::Views::Generator::color("Color: ", &this->pointLight->color);

    this->contentView->addSubview(this->colorView);
}

void Components::Views::PointLight::layoutSubviews() {
    int x = 0;
    this->colorView->frame = UIKit::CGRect(0, x, this->frame.size.width, this->colorView->height);
    x += this->colorView->height;

    this->contentView->frame = UIKit::CGRect(0, 0, this->frame.size.width, x);
    Components::Views::Base::layoutSubviews();
}
