/*
 * Copyright (c) 2015, Rémi Bazin <bazin.remi@gmail.com>
 * All rights reserved.
 * See LICENSE for licensing details.
 */

#include "iterop.h"

/*!
    \headerfile <algo/iterop>
    \inmodule Algo
    \ingroup Algo

    \title Iterable operations
    \brief This file provides operations on iterables to complete the <algorithm> library.
*/

/*!
    \relates <algo/iterop>
    Returns \c true if \a main_lst starts with \a beginning, \c false otherwise.

    \note This function uses the comparison operator == and is linear in the length of beginning.
*/
template <class InputIterator> bool starts_with(const InputIterator main_lst, const InputIterator beginning)
{
    InputIterator::iterator it1 = main_lst.begin(), it2 = beginning.begin();
    while (it2 != beginning.end())
    {
        if (it1 == main_lst.end())
            return false;
        if (!(*it1 == *it2))
            return false;
        ++it1;
        ++it2;
    }
    return true;
}
