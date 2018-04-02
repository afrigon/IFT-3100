#include "AmbientLightView.h"

Components::Views::AmbientLight::AmbientLight(Components::AmbientLight * ambientLight) : Base(ambientLight->name), ambientLight(ambientLight) {
    if(!ambientLight) return;
    this->colorView = Components::Views::Generator::color("Color: ", &this->ambientLight->color);

    this->contentView->addSubview(this->colorView);
}

void Components::Views::AmbientLight::layoutSubviews() {
    int x = 0;
    this->colorView->frame = UIKit::CGRect(0, x, this->frame.size.width, this->colorView->height);
    x += this->colorView->height;

    this->contentView->frame = UIKit::CGRect(0, 0, this->frame.size.width, x);
    Components::Views::Base::layoutSubviews();
}
