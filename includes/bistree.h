/**
 * @file bistree.h
 * @author Kyle Loudon
 * @date 11 May 2020
 * @brief Header for the Binary Search Tree Abstract Datatype.
 */

#ifndef BISTREE_H
#define BISTREE_H

#include "bitree.h"

/* @brief Define balance factors for AVL trees.
 *
 */
#define AVL_LFT_HEAVY  ( 1 )
#define AVL_BALANCED   ( 0 )
#define AVL_RGT_HEAVY  ( -1 )

/** 
 * @brief A structure for nodes in AVL trees.
 */
typedef struct AvlNode_ {
    void *data; /*!< The data stored in the node. */
    int hidden; /*!< A member used to mark a node when it is removed. */
    int factor; /*!< A node's balance factor. */
} AvlNode;

/** 
 * @brief Implement a binary search tree as binary trees. 
 */
typedef BiTree BisTree;

/**
 * 
 * @brief Initializes the binary search tree specified by tree.
 * 
 * This operation must be called for a binary search tree before the tree can be used with any
 * other operation. The function pointer compare specifies a user-defined function to compare
 * elements. This function should return 1 if key1 > key2, 0 if key1 = key2, and -1 if key1 < key2.
 * The destroy argument provides a way to free dynamically allocated when #bistree_destroy is 
 * called. It works in a manner similar to that described for #bitree_destroy. For a binary search
 * tree containing data that should not be freed, destroy should be set to NULL. The complexity is
 * O(1).
 * 
 * @param[out] tree The tree to be initialized.
 * @param[in] compare A function pointer to compare element. This function should return 1 if key1 >
 * key2, 0 if key1 = key2, and -1 if key1 < key2.
 * @param[in] destroy A function pointer to be used by #bistree_destroy to free dynamically
 * allocated data when #bistree_destroy is called.
 * @return None.
 * 
 */
void bistree_init(BisTree *tree, void (*compare)(const void *key1, const void *key2),
                  void (*destroy)(void *data));

/**
 * @brief Destroys the binary search tree specified by tree. No other operations are permitted after
 * calling #bistree_destroy unless #bistree_init is called again. The #bistree_destroy operation
 * removes all nodes from a binary search tree and calls the function passed as destroy to 
 * #bistree_init once for each node as it is removed, provided destroy was not set to NULL. The
 * complexity is O(n).
 * 
 * @param[in] tree The tree to be destroyed.
 * @return None.
 * 
 */
void bistree_destroy(BisTree *tree);

/**
 * @brief Inserts a node into the binary search tree specified by tree.
 * 
 * The new node contains a pointer to data, so the memory referenced by data should remain valid as
 * long as the node remains in the binary search tree. It is the responsibility of the caller to
 * manage the storage associated with data. The complexity is O(lg n), where n is the number of
 * nodes in the binary search tree. The complexity is O(lg n), where n is the number of nodes in the
 * binary search tree.
 * 
 * @param[out] tree The tree to insert the new node.
 * @param[in] data The data to be inserted in the tree.
 * @return 0 if inserting the node is succesful, 1 if the node is already in the tree, or -1 
 * otherwise.
 * 
 */
int bistree_insert(BisTree *tree, const void *data);

/**
 * @brief Removes the node matching data from the binary search tree specified by tree.
 * 
 * In actuality, this operation only performs a lazy removal, in which the node is simply marked as
 * hidden. Thus, no pointer is returned to the data matching data. The data in the tree must remain
 * valid even after it has been removed. Consequently, the size of the binary search tree, as
 * returned by #bistree_size, does not decrease after removing a node. This approach is explained
 * further in the implementation and analysis section. The complexity is O(lg n), where n is the
 * number of nodes in the binary search tree.
 * 
 * @param[out] tree The tree to remove the node.
 * @param[in] data The data to be removed.
 * @return 0 if removing the node is succesful, or -1 otherwise.
 * 
 */
int bistree_remove(BisTree *tree, const void *data);

/**
 * @brief Determines whether a node matches data in the binary search tree specified as tree. 
 * 
 * If a match is found, data points to the matching data in the binary search tree upon return.
 * 
 * @param[out] tree The tree to lookup for the node.
 * @param[in] data A pointer to the data to be searched. Upon return, data points to the matching
 * data in the binary search tree.
 * @return 0 if the data is found in the binary search tree, or -1 otherwise.
 * 
 */
int bistree_lookup(BisTree *tree, void **data);

/**
 * @brief Macro that evaluates to the number of nodes in the binary search tree specified by tree.
 * The complexity is O(1).
 * 
 * @param[in] tree The tree to evaluate the size
 * @return Number of nodes in the tree.
 * 
 */
#define bistree_size(tree) ((tree)->size)

#endif