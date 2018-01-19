/*
 * Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
 *
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */

#include <string>

#ifndef SRC_LOGGER_H
#define SRC_LOGGER_H
#endif  // SRC_LOGGER_H

class Logger {
 public:
    static void log(std::string message);
    static void success(std::string message);
    static void warn(std::string message);
    static void err(std::string message);
};
