//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "ComponentsDataSource.h"

int ComponentsDataSource::numberOfRows() {
    if (!go) return 0;
    return go->getComponentsCount();
}

UIKit::UITableViewCell* ComponentsDataSource::cellForRow(int index) {
    if (!go) return nullptr;
    return nullptr;
}

int ComponentsDataSource::heightForRow(int index) {
    return 0;
}
