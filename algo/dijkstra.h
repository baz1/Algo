/*
 * Copyright (c) 2015, Remi Bazin <bazin.remi@gmail.com>
 * All rights reserved.
 * See LICENSE for licensing details.
 */

#ifndef ALGO_DIJKSTRA_H
#define ALGO_DIJKSTRA_H

#include <vector>
#include <unordered_map>

#include "dijkstra_neighbor.h"

template <typename WeightType>
void dijkstra(const std::vector< std::vector< dijkstra_neighbor<WeightType> > > &adjacency_list,
              int source, std::vector<WeightType> &min_distance, std::vector<int> &previous,
              WeightType infinite_weight, int hashtable_init_capacity = 256)
{
    int N = adjacency_list.size();
    min_distance.clear();
    min_distance.resize(N, infinite_weight);
    min_distance[source] = 0;
    previous.clear();
    previous.resize(N, -1);
    std::unordered_map<int, WeightType> vertex_queue(hashtable_init_capacity);
    vertex_queue[source] = 0;
    typename std::unordered_map<int, WeightType>::iterator it_v;
    while (!vertex_queue.empty())
    {
        it_v = vertex_queue.begin();
        int vertex = it_v->first;
        WeightType dist = it_v->second;
        vertex_queue.erase(it_v);
        const std::vector< dijkstra_neighbor<WeightType> > &neighbors = adjacency_list[vertex];
        for (int i = neighbors.size(); i-- > 0;)
        {
            const dijkstra_neighbor<WeightType> &neighbor = neighbors[i];
            WeightType new_dist = dist + neighbor.weight;
            if (new_dist < min_distance[neighbor.target])
            {
                min_distance[neighbor.target] = new_dist;
                vertex_queue[neighbor.target] = new_dist;
                previous[neighbor.target] = vertex;
            }
        }
    }
}

std::vector<int> dijkstra_path(const std::vector<int> &previous, int source, int destination);

#endif // ALGO_DIJKSTRA_H
