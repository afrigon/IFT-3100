//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "ComponentsDataSource.h"

int ComponentsDataSource::numberOfRows() {
    if (!this->go) return 0;
    return this->go->getComponentsCount();
}

UIKit::UITableViewCell* ComponentsDataSource::cellForRow(int index) {
    if (!this->go) return nullptr;
    return new ComponentTableViewCell(this->go->getComponentAt(index)->getUIView());
}

int ComponentsDataSource::heightForRow(int index) {
    return this->go->getComponentAt(index)->getUIViewHeight();
}
