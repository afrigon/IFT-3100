//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//


#ifndef COMPONENTS_VIEWS_MATERIALVIEW_H_
#define COMPONENTS_VIEWS_MATERIALVIEW_H_

#include "BaseView.h"
#include "Material.h"

namespace Components {
    namespace Views {
        class MapFilePickerDelegate: public Components::Views::FilePickerDelegate {
            Components::Map* map;
            
         public:
            MapFilePickerDelegate() {}
            MapFilePickerDelegate(Components::Map* map): map(map) {}
            void didPickFile(string) override;
        };
        
        class Material: public Components::Views::Base {
            Components::Material* material = nullptr;
            
            Components::Views::ColorView* ambientColor;
            Components::Views::ColorView* diffuseColor;
            Components::Views::ColorView* specularColor;
            
            Components::Views::FilePickerView* ambientPicker;
            Components::Views::FilePickerView* diffusePicker;
            Components::Views::FilePickerView* specularPicker;
            Components::Views::FilePickerView* normalPicker;
            Components::Views::FilePickerView* reflectionPicker;
            
            Components::Views::MapFilePickerDelegate ambientDelegate;
            Components::Views::MapFilePickerDelegate diffuseDelegate;
            Components::Views::MapFilePickerDelegate specularDelegate;
            Components::Views::MapFilePickerDelegate normalDelegate;
            Components::Views::MapFilePickerDelegate reflectionDelegate;
            
            Components::Views::NumericView* brightness;
            
            Components::Views::SwitchView* illuminationMode;
            
        public:
            Material(Components::Material*);
            ~Material();
            void layoutSubviews() override;
            void setText(int tag);
            
            void click(UIView & view);
            void rightclick(UIView & view);
        };
    }  // namespace Views
}  // namespace Components

#endif  // COMPONENTS_VIEWS_MATERIALVIEW_H_



