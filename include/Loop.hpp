/*
 * Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
 *
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */

#ifndef LOOP_H
#define LOOP_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Logger.hpp"

class Loop {
    GLFWwindow* window;

 public:
    Loop() {};
    bool init();
    void start();
};

#endif  // LOOP_H
