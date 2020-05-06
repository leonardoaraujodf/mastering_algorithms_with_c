/* Header for Set Covering */

#ifndef COVER_H
#define COVER_H
#include "set.h"

/* Define a structure for subsets identified by a key */
typedef struct KSet_ {
    void *key;
    Set set;
} Kset;

/* Public Interface */

/*
 * Description: Determines a nearly optimal covering of S considering
 * the subsets A1 to An in P. The function has three arguments: 
 * members is the set S to be covered, subsets is the set of subsets 
 * in P, and covering is the set C returned as the covering. The 
 * function modifies all three sets passed to it, so copies should be 
 * made before calling the function, if necessary.
 * 
 * Return Value: Returns 0 if it finds a covering, 1 if a covering is
 * not possible, or -1 otherwise.
 * 
 * Complexity: O(m^3)
 * 
*/
int cover(Set *members, Set *subsets, Set *covering);

#endif