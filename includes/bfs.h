
/**
 * @file bfs.h
 * @author Kyle Loudon
 * @date 17 May 2020
 * @brief Header for Breadth-First Search.
 */

#ifndef BFS_H
#define BFS_H

#include "graph.h"
#include "list.h"

/*
 * @brief Define a structure for vertices in a breadth-first search.
 */
typedef struct BfsVertex_ {
   void *data;
   VertexColor color;
   int hops;
} BfsVertex;

/*
 * @brief Breadth-first search function. It used to determine the smallest number
 * of hops between nodes in a internet.
 *
 * @param[in] graph The graph to be searched, which represents the internet.
 * @param[in] start The vertex to start searching.
 * @param[in/out] hops The list of hops count that is returned.
 *
 * @return Returns 0 in success and a value less than 0 in a error.
 */
int bfs(Graph *graph, BfsVertex *start, List *hops);

#endif
