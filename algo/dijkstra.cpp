/*
 * Copyright (c) 2015, Remi Bazin <bazin.remi@gmail.com>
 * All rights reserved.
 * See LICENSE for licensing details.
 */

#include "dijkstra.h"

#include <algorithm>

/*!
    \headerfile <algo/dijkstra.h>
    \inmodule Algo
    \ingroup dijkstra

    \title dijkstra
    \brief Dijkstra's shortest path algorithm

    This file provides a modular way to use Dijkstra's shortest path algorithm.
*/

/*!
    \fn void dijkstra(const std::vector< std::vector< dijkstra_neighbor<WeightType> > > &adjacency_list,
              int source, std::vector<WeightType> &min_distance, std::vector<int> &previous,
              WeightType infinite_weight, int hashtable_init_capacity)
    \relates <algo/dijkstra.h>
    Computes the Dijkstra's algorithm in order to retrieve the minimum distances \a min_distance
    and the predecessors \a previous corresponding to the shortest paths starting at the vertex \a source.

    Vertices are labelled with integers whereas weights can have any type,
    as long as they implement the < operator, and conversion from int (0).

    \a adjacency_list defines the structure of the graph.

    \a infinite_weight shall be set to the maximum value reachable with the type \c WeightType.
    In case \c WeightType is a basic type, std::numeric_limits<WeightType>::infinity() or
    std::numeric_limits<WeightType>::max() should be used, when available.

    Finally, \a hashtable_init_capacity may be specified as a optimizing factor when the size of the
    problem is known: it is the size given to the vertex hashmap during the initialization.

    \sa dijkstra_neighbor::dijkstra_neighbor()
    \sa dijkstra_path()
*/

/*!
    \relates <algo/dijkstra.h>
    Extracts a specific shortest path in the graph.

    Extracts a path from the \a source vertex to some \a destination vertex,
    using the previously-computed vector value \a previous.
    Returns a vector of vertex identifiers, starting with \a source and ending with \a destination
    and corresponding to the shortest path according to \a previous.

    \warning For efficiency reasons, there is no check whether or not destination is reachable.
    to avoid any infinite loop behavior, please check beforehand that the \c min_distance value
    corresponding to \a destination is not infinite.

    \sa dijkstra()
*/
std::vector<int> dijkstra_path(const std::vector<int> &previous, int source, int destination)
{
    std::vector<int> result;
    result.push_back(destination);
    while (destination != source)
    {
        destination = previous[destination];
        result.push_back(destination);
    }
    std::reverse(result.begin(), result.end());
    return result;
}
