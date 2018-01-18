/*
 * Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
 *
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */

#include <stdio.h>
#include <GLFW/glfw3.h>

int main() {
    if (!glfwInit()) {
        return 1;
    }
    GLFWwindow* window = glfwCreateWindow(640,
                                          480,
                                          "My Title",
                                          NULL,
                                          NULL);
    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    return 0;
}
