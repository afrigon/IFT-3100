//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef COMPONENTS_RENDERABLE_H_
#define COMPONENTS_RENDERABLE_H_

#include "components/AbstractComponent.h"
#include "ofMain.h"

// Component that can be rendered
// TODO(xenal) : Change that inheritance to something better, it's a bad way to handle it, too lazy to change it now so deal with it for the time
class Renderable: public AbstractComponent {
 public:
    virtual void render() {}
};

#endif  // COMPONENTS_RENDERABLE_H_
