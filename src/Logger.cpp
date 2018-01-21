/*
 * Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
 *
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */

#include <iostream>
#include <string>
#include "Logger.hpp"

void Logger::log(std::string message) {
    std::cout << "\033[" << static_cast<int>(TerminalCode::blue) << "mINFO: \033[" << static_cast<int>(TerminalCode::reset) << "m" << message << std::endl;
}

void Logger::success(std::string message) {
    std::cout << "\033[" << static_cast<int>(TerminalCode::green) << "mSUCCESS: \033[" << static_cast<int>(TerminalCode::reset) << "m" << message << std::endl;
}

void Logger::warn(std::string message) {
    std::cout << "\033[" << static_cast<int>(TerminalCode::yellow) << "mWARN: \033[" << static_cast<int>(TerminalCode::reset) << "m" << message << std::endl;
}

void Logger::err(std::string message) {
    std::cout << "\033[" << static_cast<int>(TerminalCode::red) << "mERR: \033[" << static_cast<int>(TerminalCode::reset) << "m" << message << std::endl;
}
