/*
 * Copyright (c) 2015, Rémi Bazin <bazin.remi@gmail.com>
 * All rights reserved.
 * See LICENSE for licensing details.
 */

#include "strop.h"

/*!
    \headerfile <algo/strop>
    \inmodule Algo
    \ingroup Algo

    \title String operations
    \brief This file provides string operations to complete the <string> library.
*/

/*!
    \relates <algo/strop>
    Splits a string.

    Splits the string \a haystack with the separator \a needle, and returns the result as a string
    vector which members may be empty. If \a min_capacity is non-zero,
    it will be used as the initial capacity for the resulting vector.

    \note This function is linear in the length of haystack.
*/
std::vector<std::string> split(const std::string &haystack, const char needle, int min_capacity)
{
    std::vector<std::string> result;
    if (min_capacity)
        result.reserve(min_capacity);
    size_t i = 0, j;
    while ((j = haystack.find(needle, i)) != std::string::npos)
    {
        result.push_back(haystack.substr(i, j - i));
        i = j + 1;
    }
    result.push_back(haystack.substr(i));
    return result;
}

/*!
    \relates <algo/strop>
    Splits a string.

    Splits the string \a haystack with the separator \a needle, and returns the result as a string
    vector which members may be empty. If \a min_capacity is non-zero,
    it will be used as the initial capacity for the resulting vector.

    \note This function operates at most in O(nm) where m and n are the length of haystack and needle.
*/
std::vector<std::string> split(const std::string &haystack, const std::string &needle, int min_capacity)
{
    std::vector<std::string> result;
    if (min_capacity)
        result.reserve(min_capacity);
    size_t i = 0, j;
    while ((j = haystack.find(needle, i)) != std::string::npos)
    {
        result.push_back(haystack.substr(i, j - i));
        i = j + needle.length();
    }
    result.push_back(haystack.substr(i));
    return result;
}
