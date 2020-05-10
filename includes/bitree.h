/**
 * @file bitree.h
 * @author Kyle Loudon
 * @date 10 May 2020
 * @brief Header for the Binary Tree Abstract Datatype.
 */

#ifndef BITREE_H
#define BITREE_H

#include <stdlib.h>

/**
 * @brief A structure for binary tree nodes.
 */
typedef struct BiTreeNode_
{
    void *data; /*!< Data member. */
    struct BiTreeNode_ *left; /*!< Pointer to the left child node. */
    struct BiTreeNode_ *right; /*!< Pointer to the right child node. */
} BiTreeNode;

/**
 * @brief A structure for binary tree.
 */
typedef struct BiTree_
{
    int size; /*!< The number of nodes in the tree. */
    int (*compare)(const void *key1, const void *key2); /*!< Member not used by binary trees but by
    datatypes that will be derived later from binary trees. */
    void (*destroy)(void *data); /*!< The encapsulated destroy function passed to #bitree_init. */

    BiTreeNode *root; /*!< Pointer to the top of the node hierarchy. */
} BiTree;

/* ------------------------------------- Public Interface --------------------------------------- */

/**
 * @brief Initializes the binary tree specified by tree.
 * 
 * This operation must be called for a binary tree before the tree can be used with any other
 * operation. The destroy argument provides a way to free dynamically allocated data when 
 * #bitree_destroy is called. For example, if the tree contains data dynamically allocated using
 * malloc, destroy should be set to free to free the data as the binary tree is destroyed. For
 * structured data containing several dynamically allocated members, destroy should be set to a 
 * user-defined function that calls free for each dynamically allocated members as well as for the
 * structure itself. For a binary tree containing data that should not be freed, destroy should be
 * set to NULL. The complexity is O(1).
 * 
 * @param[in,out] tree The binary tree to be initialized.
 * @param[in] destroy A pointer to the user-defined destroy function to be user in #bitree_destroy.
 * @return None.
 * 
 */
void bitree_init(BiTree *tree, void (*destroy)(void *data));

/**
 * @brief Destroys the binary tree specified by tree.
 * 
 * No other operations are permitted after calling #bitree_destroy unless #bitree_init is called
 * again. The #bitree_destroy operation removes all nodes from a binary tree and calls the function
 * passed as destroy to #bitree_init once for each node as it is removed, provided destroy was not
 * set to NULL. The complexity is O(n), where n is the number of nodes in the binary tree.
 * 
 * @param[in] tree The binary tree to be destroyed.
 * @return None.
 *  
 */
void bitree_destroy(BiTree *tree);

/**
 * @brief Inserts a node as the left child of node in the binary tree specified by tree.
 * 
 * If node already has a left child, #bitree_ins_left returns -1. If node is NULL, the new node is
 * inserted as the root node. The tree must be empty to insert a node as the root node, otherwise,
 * #bitree_ins_left returns -1. When succesful, the new node contains a pointer to data, so the
 * memory referenced by data should remain valid as long as the node remains in the binary tree. It
 * is the responsibility of the caller to manage the storage associated with data. The complexity is
 * O(1).
 * 
 * @param[in,out] tree The binary tree to insert the node.
 * @param[in] node The node used by reference to insert the new node.
 * @param[in] data The data to be inserted.
 * @return 0 if inserting the node is succesful, or -1 otherwise.
 * 
 */
int bitree_ins_left(BiTree *tree, BiTreeNode *node, const void *data);

/**
 * @brief Inserts a node as the right child of node in the binary tree specified by tree.
 * 
 * If node already has a right child, #bitree_ins_right returns -1. If node is NULL, the new node is
 * inserted as the root node. The tree must be empty to insert a node as the root node, otherwise,
 * #bitree_ins_right returns -1. When succesful, the new node contains a pointer to data, so the
 * memory referenced by data should remain valid as long as the node remains in the binary tree. It
 * is the responsibility of the caller to manage the storage associated with data. The complexity is
 * O(1).
 * 
 * @param[in,out] tree The binary tree to insert the node.
 * @param[in] node The node used by reference to insert the new node.
 * @param[in] data The data to be inserted.
 * @return 0 if inserting the node is succesful, or -1 otherwise.
 * 
 */
int bitree_ins_right(BiTree *tree, BiTreeNode *node, const void *data);

/**
 * @brief Removes the subtree rooted at the left child of node from the binary tree specified by
 * tree.
 * 
 * If node is NULL, all nodes in the tree are removed. The function passed as destroy to 
 * #bitree_init is called for each node as it is removed, provided destroy was not set to NULL.
 * The complexity is O(n), where n is the number of nodes in the subtree.
 * 
 * @param[in,out] tree The binary tree to remove the node.
 * @param[in,out] data A pointer to the data to be removed. Upon return, returns the pointer to the
 * data removed.
 * @return None.
 * 
 */
void bitree_rem_left(BiTree *tree, BiTreeNode *node);

/**
 * @brief Removes the subtree rooted at the right child of node from the binary tree specified by
 * tree.
 * 
 * If node is NULL, all nodes in the tree are removed. The function passed as destroy to
 * #bitree_init is called for each node as it is removed, provided destroy was not set to NULL.
 * The complexity is O(n), where n is the number of nodes in the subtree.
 * 
 * @param[in,out] tree The binary tree to remove the node.
 * @param[in,out] data A pointer to the data to be removed. Upon return, returns the pointer to the
 * data removed.
 * @return None.
 * 
 */
void bitree_rem_right(BiTree *tree, BiTreeNode *node);

/**
 * @brief Merges the two binary trees specified by left and right into the single binary tree merge.
 * 
 * After merging is complete, merge contains data in its root node, and left and right are the left
 * and right subtrees of its root. Once the trees have been merged, left and right are as if 
 * #bitree_destroy had been called on them. The complexity is O(1).
 * 
 * @param[in,out] merge The tree resulting from the merge.
 * @param[in] left The left tree to be merged.
 * @param[in] right The right tree to be merged.
 * @param[in] data The data to be inserted in the root node.
 * @return 0 if merging the trees is succesful, or -1 otherwise.
 * 
 */
int bitree_merge(BiTree *merge, BiTree *left, BiTree *right, const void *data);

/**
 * @brief Macro that evaluates to the number of nodes in the binary tree specified by tree. The
 * complexity is O(1).
 * @return Number of nodes in the tree.
 * 
 */
#define bitree_size(tree)((tree)->size)

/**
 * @brief Macro that evaluates to the node at the root of the binary tree specified by tree. The
 * complexity is O(1).
 * @return Node at the root of the tree.
 * 
 */
#define bitree_root(tree)((tree)->root)

/**
 * @brief Macro that determines whether the node specified as node marks the end of a branch in a 
 * binary tree.
 * @return 1 if the node marks the end of a branch, or 0 otherwise.
 * 
 */
#define bitree_is_eob(node)(node == NULL)

/**
 * @brief Macro that determines whether the node specified as node is a leaf node in a binary tree.
 * @return 1 if the node is a leaf node, or 0 otherwise.
 */
#define bitree_is_leaf(node)((node)->left == NULL && (node)->right == NULL)

/**
 * @brief Macro that evaluates to the data stored in the node of a binary tree specified by node.
 * @return Data stored in the node.
 * 
 */
#define bitree_data(node)((node)->data)

/**
 * @brief Macro that evaluates to the node of a binary tree that is the left child of the node
 * specified by node.
 * @return Left child of the specified node.
 */
#define bitree_left(node)((node)->left)

/**
 * @brief Macro that evaluates to the node of a binary tree that is the right child of the node
 * specified by node.
 * @return Right child of the specified node.
 */
#define bitree_right(node)((node)->right)

#endif