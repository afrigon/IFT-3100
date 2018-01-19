/*
 * Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
 *
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */

#include "Logger.h"
#include <iostream>
#include <string>

void Logger::log(std::string message) {
    std::cout << "\033[34mINFO: \033[0m" << message << std::endl;
}

void Logger::success(std::string message) {
    std::cout << "\033[32mSUCCESS: \033[0m" << message << std::endl;
}

void Logger::warn(std::string message) {
    std::cout << "\033[33mWARN: \033[0m" << message << std::endl;
}

void Logger::err(std::string message) {
    std::cout << "\033[31mERR: \033[0m" << message << std::endl;
}
