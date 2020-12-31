/**
 * @file graph.h
 * @author Kyle Loudon
 * @date 17 May 2020
 * @brief Header for the Graph Abstract Datatype.
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include "list.h"
#include "set.h"

/*
 * @brief Define a structure for adjacency lists.
 */
typedef struct AdjList_ {
   void *vertex;
   Set adjacent;
} AdjList;

/*
 * @brief Define a structure for graphs.
 */
typedef struct Graph_ {
   int vcount;
   int ecount;
   int (*match)(const void *key1, const void *key2);
   void (*destroy)(void *data);
   List adjlists;
} Graph;

/*
 * @brief Define colors for vertices in a graph.
 */
typedef enum VertexColor_ {white, gray, black} VertexColor;

/*
 * @brief Initializes the graph specified by graph. 
 *
 * This operation must be called for a graph before the graph can be used with any other operation.
 * The match argument is a function used by various graph operations to determine if two vertices
 * match. It should return 1 if key1 is equal to key2, and 0 otherwise. The destroy argument
 * provide a way to free dynamically allocated data when #graph_destroy is called. For example, if
 * the graph contains data dynamically allocated using malloc, destroy should be set to free to free
 * the data as the graphs is destroyed. For structured data containing several dynamically allocated
 * members, destroy should be set to a user-defined function that calls free for each dynamically
 * allocated member, as well as for the structure itself. For a graph contaning data that should not
 * be freed, destroy should be set to NULL.
 * Complexity: O(1).
 *
 * param[in] graph The graph to be initialized.
 * param[in] match The user match function to determine if two vertices match.
 * param[in] destroy The user destroy function to free all data dynamically allocated.
 *
 * @return None.
 *
 */
void graph_init(Graph *graph, int (*match)(const void *key1, const void *key2), void (*destroy)(void *data));

/*
 * @brief Destroys the graph specified by graph.
 *
 * No other operations are permitted after calling #graph_destroy unless #graph_init is called again.
 * The #graph_destroy operation removes all vertices and edges from a graph and calls the function
 * passed as destroy to #graph_init once for each vertex or edge as it is removed, provided destroy
 * is not set to NULL.
 * Complexity: O(V + E), where V is the number of vertices in the graph and E is the number of edges.
 *
 * @return None.
 */
void graph_destroy(Graph *graph);

/*
 * @brief Insert a vertex into the graph specified by graph.
 *
 * The new vertex contains a pointer to data, so the memory referenced by data should remain valid as
 * long as the vertex remains in the graph. It is the responsibility of the caller to manage the storage
 * associated with data.
 * Complexity: O(V), where V is the number of vertices in the graph.
 *
 * @return 0 if inserting the vertex is succesful, 1 if the vertices already exists, or -1 otherwise.
 *
 */
int graph_ins_vertex(Graph *graph, const void *data);

/*
 * @brief Inserts and edge from vertex specified by data1 to the vertex specified by data2 in graph specified
 * by graph.
 *
 * Both vertices must have been inserted previously using #graph_ins_vertex. The new edge is represented with
 * a pointer to data2 in the adjacency list of vertex specified by data1, so the memory referenced by data2
 * should remain valid as long as the edge remains in the graph. It is the responsibility of the called to
 * manage the storage associated with data2. To enter an edge (u, v) in an undirected graph, call this operation
 * twice: once to insert an edge from u to v, and again to insert the implied edge from v to u. This type of
 * representation is common for undirected graphs.
 * Complexity: O(V), where V is the number of vertices in the graph.
 *
 * @return 0 if inserting the edge is succesful, 1 if the edge already exists, or -1 otherwise.
 *
 */
int graph_ins_edge(Graph *graph, const void *data1, const void *data2);

/*
 * @brief Remove the vertex matching data from the graph specified by graph.
 *
 * All edges incident to an from the vertex must have been removed previously using #graph_rem_edge.
 * Upon return, data points to the data stored in the vertex that was removed. It is the responsibility
 * of the caller to manage the storage associated with the data.
 * Complexity: O(V+E), where V is the number of vertices in the graph and E is the number of edges.
 *
 * @return 0 if removing the vertex is successful, -1 otherwise.
 *
 */
int graph_rem_vertex(Graph *graph, void **data);

/*
 * @brief Removes the edge from data1 to data2 in the graph specified by graph.
 *
 * Upon return, data2 points to the data stored in the adjacency list of the vertex specified by data1.
 * It is the responsibility of the caller to manage the storage associated with the data.
 * Complexity: O(V), where V is the number of vertices in the graph.
 *
 * @return 0 if removing the edge is successful, or -1 otherwise.
 *
 */
int graph_rem_edge(Graph *graph, void *data1, void **data2);

/*
 * @brief Retrieves vertices that are adjacent to the vertex specified by data in graph.
 *
 * The adjacent vertices are return in the form of AdjList structure, a structure containing
 * the vertex matching data and a set of vertices adjacent to it. A pointer to the actual
 * adjacency list in the graph is returned, so it must not be manipulated by the caller.
 * Complexity: O(V), where V is the number of vertices in the graph.
 *
 * @return 0 if retrieving the adjacency list is succesful, or -1 otherwise.
 *
 */
int graph_adjlist(const Graph *graph, const void *data, AdjList **adjlist);

/*
 * @brief Determines whether the vertex specified by data2 is adjacent to the vertex specified
 * by data1 in graph.
 * Complexity: O(V), where V is the number of vertices in the graph.
 *
 * @return 1 if the second vertex is adjacent to the first vertex, 0 otherwise.
 *
 */
int graph_is_adjacent(const Graph *graph, const void *data1, const void *data2);

/*
 * @brief Macro that evaluates to the list of adjacency-list structures in the graph. Each element
 * in the list is an AdjList structure. The actual list of adjacency-list structures in the graph
 * is returned, so it must not be manipulated by the caller.
 * Complexity: O(1).
 *
 * @return List of adjacency-list structures.
 *
 */
#define graph_adjlists(graph) ((graph)->adjlists);

/*
 * @brief Macro that evaluates to the number of vertices in the graph specified by graph.
 * Complexity: O(1).
 *
 * @return Number of vertices in the graph.
 */
#define graph_vcount(graph) ((graph)->vcount);

/*
 * @brief Macro that evaluates to the number of edges in the graph specified by graph.
 * Complexity: O(1).
 *
 * @return Number of edges in the graph.
 *
 */
#define graph_ecount(graph) ((graph)->ecount);

#endif
