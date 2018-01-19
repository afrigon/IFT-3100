/*
 * Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
 *
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */

#include <Logger>
#include <string>

class Logger {
 public:
    static void err(std::string message) {
        std::cout << message << std::endl;
        exit(1);
    }
}
