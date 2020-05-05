/* Header for the Set Abstract Datatype */

#ifndef SET_H
#define SET_H

#include <stdio.h>
#include "list.h"

/* Implement sets as linked lists */
typedef List Set;

/* --------------------- Public Interface ------------------------ */

/*
 * Description: Initializes the set specified by set. This operation
 * must be called for a set before the set can be used with any
 * other operation. The match argument is a function used by various
 * set operations to determine if two members match. It should
 * return 1 if key1 is equal to key2, and 0 otherwise. The destroy
 * argument provides a way to free dynamically allocated data when
 * set_destroy is called. For example, if the set contains data
 * dynamically allocated using malloc, destroy should be set to free
 * to free the data as the set is destroyed. For structured data
 * containing several dynamically allocated members, destroy should
 * be set to a user-defined function that call free for each
 * dynamically allocated member as well as for the structure itself.
 * For a set containing data that should not be freed, destroy should
 * be set to NULL.
 * 
 * Return Value: None.
 * 
 * Complexity: O(1)
 * 
 */
void set_init(Set *set, int (*match)(const void *key1,
    const void *key2), void (*destroy)(void *data));

/*
 * Description: Destroys the set specified by set. No other operations
 * are permitted after calling set_destroy unless set_init is called
 * again. The set_destroy operation removes all members from a set
 * and calls the function passed as destroy to set_init once for each
 * member as it is removed, provided destroy was not set to NULL.
 * 
 * Return Value: None.
 * 
 * Complexity: O(n), where n is the number of members in the set.
 * 
 */
#define set_destroy list_destroy

/*
 * Description: Inserts a member into the set specified by set. The 
 * new member contains a pointer to data, so the memory referenced by
 * data should remain valid as long as the member remains in the set.
 * It is the responsibility of the caller to manage the storage with
 * data.
 * 
 * Return Value: 0 if inserting the member is succesful, 1 if the
 * member is already in the set, or -1 otherwise.
 * 
 * Complexity: O(n), where n is the number of members in the set.
 * 
 */
int set_insert(Set *set, const void *data);

/*
 * Description: Removes the member matching data from the set 
 * specified by set. Upon return, data points to the data stored in
 * the member that was removed. It is the responsibility of the caller
 * to manage the storage associated with the data.
 *
 * Return Value: 0 if removing the member is succesful, or 
 * -1 otherwise.
 * 
 * Complexity: O(n), where n is the number of members in the set.
 * 
 */
int set_remove(Set *set, void **data);

/*
 * Description: Builds a set that is the union of set1 and set2.
 * Upon return, setu contains the union. Because setu points to data
 * in set1 and set2, the data in set1 and set2 must remain valid until
 * setu is destroyed with set_destroy.
 *
 * Return Value: 0 if computing the union is succesful, or 
 * -1 otherwise.
 * 
 * Complexity: O(mn), where m and n are the number of members in set1
 * and set2, respectively.
 * 
 */
int set_union(Set *setu, const Set *set1, const Set *set2);

/*
 * Description: Builds a set that is the intersection of set1 and
 * set2. Upon return, seti contains the intersection. Because seti
 * points to data in set1, the data in set1 must remain valid until
 * seti is destroyed with set_destroy.
 *
 * Return Value: 0 if computing the intersection is succesful, or -1
 * otherwise.
 * 
 * Complexity: O(mn), where m and n are the number of members in set1
 * and set2, respectively.
 * 
 */
int set_intersection(Set *seti, const Set *set1, const Set *set2);

/*
 * Description: Builds a set that is the difference of set1 and set2.
 * Upon return, setd contains the difference. Because setd points to
 * data in set1, the data in set1 must remain valid until setd is 
 * destroyed with set_destroy.
 *
 * Return Value: 0 if computing the difference is succesful, or -1
 * otherwise.
 * 
 * Complexity: O(mn), where m and n are the number of members in set1
 * and set2, respectively.
 * 
 */
int set_difference(Set *setd, const Set *set1, const Set *set2);

/*
 * Description: Determines whether the data specified by data matches
 * that of a member in the set specified by set.
 *
 * Return Value: 1 if the member is found, or 0 otherwise.
 * 
 * Complexity: O(n), where n is the number of members in the set.
 * 
 */
int set_is_member(const Set *set, const void *data);

/*
 * Description: Determines whether the set specified by set1 is a 
 * subset of the set specified by set2.
 *
 * Return Value: 1 if the set is a subset, or 0 otherwise.
 * 
 * Complexity: O(mn), where m and n are the number of members in set1
 * and set2, respectively.
 * 
 */
int set_is_subset(const Set *set1, const Set *set2);

/*
 * Description: Determines whether the set specified by set1 is equal
 * to the set specified by set2.
 *
 * Return Value: 1 if the two sets are equal, or 0 otherwise.
 * 
 * Complexity: O(mn), where m and n are the number of members in set1
 * and set2, respectively.
 * 
 */
int set_is_equal(const Set *set1, const Set *set2);

/*
 * Description: Macro that evaluates to the number of members in the
 * set specified by set.
 *
 * Return Value: Number of members in the set.
 * 
 * Complexity: O(1)
 * 
 */
#define set_size(set) ((set)->size)

#endif