/**
 * @file bitree.c
 * @author Kyle Loudon
 * @date 10 May 2020
 * @brief Implementation of the Binary Tree Abstract Datatype.
 */

#include <stdlib.h>
#include <string.h>

#include "bitree.h"

void bitree_init(BiTree *tree, void (*destroy)(void *data))
{
    /* Initialize the binary tree. */
    tree->size = 0;
    tree->destroy = destroy;
    tree->root = NULL;

    return;
}

void bitree_destroy(BiTree *tree)
{
    /* Remove all nodes from the tree. */
    bitree_rem_left(tree, NULL);

    /* No operations are allowed now, but clear the structure as a precaution. */
    memset(tree, 0, sizeof(BiTree));

    return;
}

int bitree_ins_left(BiTree *tree, BiTreeNode *node, const void *data)
{
    BiTreeNode *new_node, **position;

    /* Determine where to insert the node. */
    if (node == NULL)
    {
        /* Allow insertion at the root only in an empty tree. */
        if (bitree_size(tree) > 0)
            return -1;
        
        position = &tree->root;
    }
    else
    {
        /* Normally allow insertion only at the end of a branch. */
        if (bitree_left(node) != NULL)
            return -1;
        
        position = &node->left;
    }

    /* Allocate storage for the node. */
    if ((new_node = (BiTreeNode *)malloc(sizeof(BiTreeNode))) == NULL)
        return -1;
    
    /* Insert the node into the tree. */

    new_node->data = (void *)data;
    new_node->left = NULL;
    new_node->right = NULL;
    *position = new_node;

    /* Adjust the size of the tree to account for the inserted node. */
    tree->size++;

    return 0;
    
}

int bitree_ins_right(BiTree *tree, BiTreeNode *node, const void *data)
{
    BiTreeNode *new_node, **position;

    /* Determine where to insert the node. */
    if (node == NULL)
    {
        /* Allow insertion at the root only if an empty tree */
        if (bitree_size(tree) > 0)
            return -1;
        
        position = &tree->root;
    }
    else
    {
        /* Normally allow insertion only at the end of a branch. */
        if (bitree_right(node) != NULL)
            return -1;
        
        position = &node->right;
    }

    /* Allocate storage for the node. */
    if ((new_node = (BiTreeNode *)malloc(sizeof(BiTreeNode))) == NULL)
        return -1;

    /* Insert the node into the tree */
    new_node->data = (void *)data;
    new_node->left = NULL;
    new_node->right = NULL;
    *position = new_node;

    /* Adjust the size of the tree to account for the inserted node. */
    tree->size++;

    return 0;
    
}

void bitree_rem_left(BiTree *tree, BiTreeNode *node)
{
    BiTreeNode **position;

    /* Do not allow removal from an empty tree */
    if (bitree_size(tree) == 0)
        return;
    
    /* Determine where to remove nodes. */
    if (node == NULL)
        position = &tree->root;
    else
        position = &node->left;
    
    /* Remove the nodes. */
    if (*position != NULL)
    {
        bitree_rem_left(tree, *position);
        bitree_rem_right(tree, *position);

        if (tree->destroy != NULL)
        {
            /* Call a user-defined function to free dynamically allocated data. */
            tree->destroy((*position)->data);
        }

        free(*position);
        *position = NULL;

        /* Adjust the size of the tree to account for the removed node. */
        tree->size--;
    }

    return;
}

void bitree_rem_right(BiTree *tree, BiTreeNode *node)
{
    BiTreeNode **position;

    /* Do not allow removal from an empty tree. */
    if (bitree_size(tree) == 0)
        return;
    
    /* Determine where to remove nodes. */
    if (node == NULL)
        position = &tree->root;
    else
        position = &node->right;

    /* Remove the nodes. */
    if (*position != NULL)
    {
        bitree_rem_left(tree, *position);
        bitree_rem_right(tree, *position);

        if (tree->destroy != NULL)
        {
            /* Call a user-defined function to free dynamically allocated data. */
            tree->destroy((*position)->data);
        }

        free(*position);
        *position = NULL;

        /* Adjust the sie of the tree to account for the removed node. */
        tree->size--;
    }

    return;

}

int bitree_merge(BiTree *merge, BiTree *left, BiTree *right, const void *data)
{
    /* Initialize the merged tree. */
    bitree_init(merge, left->destroy);

    /* Insert the data for the root node of the merged tree. */
    if (bitree_ins_left(merge, NULL, data) != 0)
    {
        bitree_destroy(merge);
        return -1;
    }

    /* Merge the two binary trees into a single binary tree. */
    bitree_root(merge)->left = bitree_root(left);
    bitree_root(merge)->right = bitree_root(right);

    /* Adjust the size of the new binary tree. */
    merge->size = merge->size + bitree_size(left) + bitree_size(right);

    /* Do not let the original trees acces the merged nodes. */

    left->root = NULL;
    left->size = 0;
    right->root = NULL;
    right->size = 0;

    return 0;
}