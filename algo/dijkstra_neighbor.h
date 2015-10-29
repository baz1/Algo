/*
 * Copyright (c) 2015, Rémi Bazin <bazin.remi@gmail.com>
 * All rights reserved.
 * See LICENSE for licensing details.
 */

#ifndef ALGO_DIJKSTRA_NEIGHBOR_H
#define ALGO_DIJKSTRA_NEIGHBOR_H

template <typename WeightType> struct dijkstra_neighbor
{
    int target;
    WeightType weight;
    inline dijkstra_neighbor(int target, WeightType weight) : target(target), weight(weight) {}
};

#endif // ALGO_DIJKSTRA_NEIGHBOR_H
