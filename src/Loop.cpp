/*
 * Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
 *
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */

#include "Loop.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

bool Loop::init() {
    Logger::log("initializing GLFW...");
    if (!glfwInit()) {
        Logger::err("failed to initialize GLFW");
        return false;
    }
    Logger::success("initialized GLFW");
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    Logger::log("creating window...");
    this->window = glfwCreateWindow(640, 480, "YOLO", NULL, NULL);
    if (this->window == nullptr) {
        Logger::err("failed to create window");
        Logger::log("cleaning up GLFW...");
        glfwTerminate();
        return false;
    }
    Logger::success("created window");
    glfwMakeContextCurrent(this->window);
    Logger::log("initializing GLAD...");
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        Logger::err("failed to initialize GLAD");
        Logger::log("cleaning up GLFW...");
        glfwTerminate();
        return false;
    }
    Logger::success("initialized GLAD");
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    return true;
}

void Loop::start() {
    Logger::log("starting main loop");
    while (!glfwWindowShouldClose(window)) {
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    Logger::log("cleaning up GLFW...");
    glfwTerminate();
}
