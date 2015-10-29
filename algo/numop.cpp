/*
 * Copyright (c) 2015, Rémi Bazin <bazin.remi@gmail.com>
 * All rights reserved.
 * See LICENSE for licensing details.
 */

#include "numop.h"

/*!
    \headerfile <algo/numop.h>
    \inmodule Algo
    \ingroup Algo

    \title numop
    \brief Numeric operations

    This file provides numeric operations to complete the <cmath> library.
*/

/*!
    \typedef uint
    \relates <algo/numop.h>

    Synonym for unsigned int.
*/

/*!
    \typedef ll
    \relates <algo/numop.h>

    Synonym for long long.
*/

/*!
    \typedef ull
    \relates <algo/numop.h>

    Synonym for unsigned long long.
*/

/*!
    \fn T qAbs(const T &t)
    \relates <algo/numop.h>
    Returns the absolute value of the number \a t.

    \note The name has been chosen to be the same one as in the Qt library
    to ease the memorizing.
    \note This method is using the comparison \tt{(t >= 0)}.
*/

/*!
    \fn const T &qMin(const T &a, const T &b)
    \relates <algo/numop.h>
    Returns the minimum between \a a and \a b.

    \note The name has been chosen to be the same one as in the Qt library
    to ease the memorizing.
    \note This method is using the comparison operator <.
*/

/*!
    \fn const T &qMax(const T &a, const T &b)
    \relates <algo/numop.h>
    Returns the maximum between \a a and \a b.

    \note The name has been chosen to be the same one as in the Qt library
    to ease the memorizing.
    \note This method is using the comparison operator <.
*/

/*!
    \fn T gcd(T a, T b)
    \relates <algo/numop.h>
    Returns the Greatest Common Divisor of \a a and \a b.
*/

/*!
    \fn std::tuple<T,T,T> gcdex(T v1, T v2)
    \relates <algo/numop.h>
    Computes the Greatest Common Divisor of \a v1 and \a v2 using the extended Euclidean algorithm.

    Returns the result as a tuple \tt{(x1,x2,gcd)} where \c gcd is the greatest common divisor,
    and \c x1 and \c x2 are such that \tt{(gcd == x1*v1 + x2*v2)}.
*/

/*!
    \fn std::tuple<T,T,T,T> gcdex2(T v1, T v2)
    \relates <algo/numop.h>
    Computes the Greatest Common Divisor of \a v1 and \a v2 using the extended Euclidean algorithm.

    Returns the result as a tuple \tt{(x1,x2,gcd,q1,q2)} where \c gcd is the greatest common divisor,
    and the other values are such that \tt{((gcd == x1*v1 + x2*v2) && (q1 == v1/gcd) && (q2 == v2/gcd)}.

    \note This version does not bring anything new to \l gcdex() when used with usual integer types
    since \c q1 and \c q2 can be easily computed afterwards, but it may be useful when manipulating
    big integers because the division operation may be costly.
*/

/*!
    \fn T tpow(const T a, int p)
    \relates <algo/numop.h>
    Returns the value of \a a to the power \a b.

    \note This function uses the square exponentiation method.
*/
