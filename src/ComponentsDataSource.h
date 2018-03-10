//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef COMPONENTSDATASOURCE_H_
#define COMPONENTSDATASOURCE_H_

#include "UIKit.h"
#include "GameObject.h"
#include "ComponentTableViewCell.h"

class ComponentsDataSource: public UIKit::UITableViewDataSource {
    int numberOfRows() override;
    UIKit::UITableViewCell* cellForRow(int index) override;
    int heightForRow(int index) override;
    
 public:
    GameObject* go;
};

#endif  // COMPONENTSDATASOURCE_H_
