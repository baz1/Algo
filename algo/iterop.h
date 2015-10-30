/*
 * Copyright (c) 2015, Remi Bazin <bazin.remi@gmail.com>
 * All rights reserved.
 * See LICENSE for licensing details.
 */

#ifndef ALGO_ITEROP_H
#define ALGO_ITEROP_H

template <class InputIterator> bool starts_with(const InputIterator main_lst, const InputIterator beginning)
{
    typename InputIterator::iterator it1 = main_lst.begin(), it2 = beginning.begin();
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

#endif // ALGO_ITEROP_H
