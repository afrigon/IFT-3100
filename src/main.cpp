/*
 * Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
 *
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */

#include "Loop.hpp"

int main() {
    Loop* loop = new Loop();
    if (!loop->init()) { return 1; }
    loop->start();
    return 0;
}
