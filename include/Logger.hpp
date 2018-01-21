/*
 * Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
 *
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <string>

struct Logger {
    static void log(std::string message);
    static void success(std::string message);
    static void warn(std::string message);
    static void err(std::string message);
};

enum class TerminalCode {
    reset=0,
    red=31,
    green=32,
    yellow=33,
    blue=34
};

#endif  // LOGGER_H
