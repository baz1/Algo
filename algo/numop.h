/*
 * Copyright (c) 2015, Rémi Bazin <bazin.remi@gmail.com>
 * All rights reserved.
 * See LICENSE for licensing details.
 */

#ifndef ALGO_NUMOP_H
#define ALGO_NUMOP_H

#include <algorithm>
#include <tuple>

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#ifdef QT_VERSION /* Are we using Qt? */
 #include <QtGlobal>
 #ifndef ASSERT
  #define ASSERT(x) Q_ASSERT(x)
 #endif
#else
template <typename T> inline T qAbs(const T &t) { return t >= 0 ? t : -t; }
template <typename T> inline const T &qMin(const T &a, const T &b) { return (a < b) ? a : b; }
template <typename T> inline const T &qMax(const T &a, const T &b) { return (a < b) ? b : a; }
 #ifndef ASSERT
  #define ASSERT(x) (void) 0
 #endif
#endif

template <typename T> T gcd(T a, T b)
{
    ASSERT((a >= 0) && (b >= 0));
    T c;
    if (b < a)
        goto invcase;
    while (true)
    {
        if (a == 0)
            return b;
        b %= a;
invcase:
        if (b == 0)
            return a;
        a %= b;
    }
}

template <typename T> std::tuple<T,T,T> gcdex(T v1, T v2)
{
    ASSERT((v1 >= 0) && (v2 >= 0));
    T a1 = 1, b1 = 0, a2 = 0, b2 = 1, q;
    if (v1 < v2)
    {
        if (v1 == 0)
            return std::tuple<T,T,T>(a2, b2, v2);
        goto invcase;
    } else {
        if (v2 == 0)
            return std::tuple<T,T,T>(a1, b1, v1);
        goto normalcase;
    }
    while (true)
    {
        if (v2 == 0)
            return std::tuple<T,T,T>(a1, b1, v1);
        a2 -= q * a1;
        b2 -= q * b1;
normalcase:
        q = v1 / v2;
        v1 -= q * v2;
        if (v1 == 0)
            return std::tuple<T,T,T>(a2, b2, v2);
        a1 -= q * a2;
        b1 -= q * b2;
invcase:
        q = v2 / v1;
        v2 -= q * v1;
    }
}

template <typename T> std::tuple<T,T,T,T,T> gcdex2(T v1, T v2)
{
    ASSERT((v1 >= 0) && (v2 >= 0));
    T a1 = 1, b1 = 0, a2 = 0, b2 = 1, q;
    if (v1 < v2)
        goto invcase;
    while (true)
    {
        if (v2 == 0)
            return std::tuple<T,T,T,T,T>(a1, b1, v1, qAbs(b2), qAbs(a2));
        q = v1 / v2;
        v1 -= q * v2;
        a1 -= q * a2;
        b1 -= q * b2;
invcase:
        if (v1 == 0)
            return std::tuple<T,T,T,T,T>(a2, b2, v2, qAbs(b1), qAbs(a1));
        q = v2 / v1;
        v2 -= q * v1;
        a2 -= q * a1;
        b2 -= q * b1;
    }
}

#endif // ALGO_NUMOP_H
