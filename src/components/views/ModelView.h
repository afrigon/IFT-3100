//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//


#ifndef COMPONENTS_VIEWS_MODELVIEW_H_
#define COMPONENTS_VIEWS_MODELVIEW_H_

#include "BaseView.h"
#include "Model.h"

namespace Components {
    namespace Views {
        class Model: public Components::Views::Base, public Components::Views::FilePickerDelegate {
            Components::Model* model = nullptr;
            Components::Views::FilePickerView* filePicker;
            
        public:
            Model(Components::Model*);
            void layoutSubviews() override;
            void didPickFile(string) override;
        };
    }  // namespace Views
}  // namespace Components

#endif  // COMPONENTS_VIEWS_MODELVIEW_H_


