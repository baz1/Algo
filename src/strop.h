/*
 * Copyright (c) 2015, Rémi Bazin <bazin.remi@gmail.com>
 * All rights reserved.
 * See LICENSE for licensing details.
 */

#ifndef ALGO_STROP_H
#define ALGO_STROP_H

#include <vector>
#include <string>

std::vector<std::string> split(const std::string &haystack, const char needle, int min_capacity = 0);
std::vector<std::string> split(const std::string &haystack, const std::string &needle, int min_capacity = 0);

#endif // ALGO_STROP_H
