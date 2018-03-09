//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef COMPONENTS_UNDELETABLE_H_
#define COMPONENTS_UNDELETABLE_H_

#include "components/AbstractComponent.h"

// if this is found on a component, prevent it from being deleted, such as the transform
// TODO(xenal) : Change that inheritance to something better, it's bad way to handle it, too lazy to change it now so deal with it for the time
class Undeletable : public AbstractComponent {};

#endif  // COMPONENTS_UNDELETABLE_H_
