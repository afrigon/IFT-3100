//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//


#ifndef COMPONENTS_VIEWS_TEXTUREVIEW_H_
#define COMPONENTS_VIEWS_TEXTUREVIEW_H_

#include "BaseView.h"
#include "Texture.h"

namespace Components {
namespace Views {
class Texture: public Components::Views::Base, public Components::Views::FilePickerDelegate {
    Components::Texture* texture = nullptr;
    Components::Views::FilePickerView* filePicker;
    //some other picker for the wrap mode
    
public:
    Texture(Components::Texture*);
    void layoutSubviews() override;
    void didPickFile(string) override;
};
}  // namespace Views
}  // namespace Components

#endif  // COMPONENTS_VIEWS_TEXTUREVIEW_H_



