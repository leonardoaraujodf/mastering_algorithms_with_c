/**
 * @file traverse.h
 * @author Kyle Loudon
 * @date 10 May 2020
 * @brief Header for Functions for Traversing a Binary Tree.
 */

#ifndef TRAVERSE_H
#define TRAVERSE_H

#include "bitree.h"
#include "list.h"

/**
 * @brief Traverse the binary tree using a preorder traversal, inserting the data elements that are
 * find.
 * 
 * Consider a tree like that:
 * 
 *                          11
 *                        /    \
 *                      51     65
 *                     / \     / \
 *                   14   32  23  17
 *                  / \
 *                74   10
 * 
 * Using a preorder traversal yields: 11 51 14 74 10 32 65 23 17
 * 
 * @param[in] node The node to be verified.
 * @param[in,out] list The list to insert the elements in the order specified.
 * 
 */
int preorder(const BiTreeNode *node, List *list);

/**
 * @brief Traverse the binary tree using a inorder traversal, inserting the data elements that are
 * find.
 * 
 * Consider a tree like that:
 * 
 *                          11
 *                        /    \
 *                      51     65
 *                     / \     / \
 *                   14   32  23  17
 *                  / \
 *                74   10
 * 
 * Using a inorder traversal yields: 74 14 10 51 32 11 23 65 17
 * 
 * @param[in] node The node to be verified.
 * @param[in,out] list The list to insert the elements in the order specified.
 * 
 */
int inorder(const BiTreeNode *node, List *list);

/**
 * @brief Traverse the binary tree using a postorder traversal, inserting the data elements that are
 * find.
 * Consider a tree like that:
 * 
 *                          11
 *                        /    \
 *                      51     65
 *                     / \     / \
 *                   14   32  23  17
 *                  / \
 *                74   10
 * 
 * Using a postorder traversal yields: 74 10 14 32 51 23 17 65 11
 * 
 * @param[in] node The node to be verified.
 * @param[in,out] list The list to insert the elements in the order specified.
 * 
 */
int postorder(const BiTreeNode *node, List *list);

#endif