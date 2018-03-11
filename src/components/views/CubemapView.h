//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//


#ifndef COMPONENTS_VIEWS_CUBEMAPVIEW_H_
#define COMPONENTS_VIEWS_CUBEMAPVIEW_H_

#include "BaseView.h"
#include "Cubemap.h"

namespace Components {
namespace Views {
class Cubemap: public Components::Views::Base, public Components::Views::FilePickerDelegate {
    Components::Cubemap* cubemap = nullptr;
    Components::Views::FilePickerView* filePicker;
    Components::Views::NumericView* distanceView;
    
public:
    Cubemap(Components::Cubemap*);
    ~Cubemap();
    void layoutSubviews() override;
    void didPickFile(string) override;
    void click(UIKit::UIView &);
    void rightclick(UIKit::UIView &);
};
}  // namespace Views
}  // namespace Components

#endif  // COMPONENTS_VIEWS_CUBEMAPVIEW_H_




