/**
 * @file bistree.c
 * @author Kyle Loudon
 * @date 13 May 2020
 * @brief Implementation of the Binary Search Tree Abstract Datatype.
 */

#include <stdlib.h>
#include <string.h>

#include "bistree.h"

static void _destroy_right(BisTree *tree, BiTreeNode *node);

static void _rotate_left(BiTreeNode **node)
{
    BiTreeNode *left, *grandchild;

    left = bitree_left(*node);

    if (((AvlNode *)bitree_data(left))->factor == AVL_LFT_HEAVY)
    {
        /*
         * Perform an LL rotation.
        */
       bitree_left(*node) = bitree_right(left);
       bitree_right(left) = *node;
       ((AvlNode *)bitree_data(*node))->factor = AVL_BALANCED;
       ((AvlNode *)bitree_data(left))->factor = AVL_BALANCED;
       *node = left;
    }
    else
    {
        /*
         * Perform an LR rotation.
         */
        grandchild = bitree_right(left);
        bitree_right(left) = bitree_left(grandchild);
        bitree_left(grandchild) = left;
        bitree_left(*node) = bitree_right(grandchild);
        bitree_right(grandchild) = *node;

        switch (((AvlNode *)bitree_data(grandchild))->factor)
        {
            case AVL_LFT_HEAVY:

                ((AvlNode *)bitree_data(*node))->factor = AVL_RGT_HEAVY;
                ((AvlNode *)bitree_data(left))->factor = AVL_BALANCED;
                break;

            case AVL_BALANCED:

                ((AvlNode *)bitree_data(*node))->factor = AVL_BALANCED;
                ((AvlNode *)bitree_data(left))->factor = AVL_BALANCED;
                break;

            case AVL_RGT_HEAVY:

                ((AvlNode *)bitree_data(*node))->factor = AVL_BALANCED;
                ((AvlNode *)bitree_data(left))->factor = AVL_LFT_HEAVY;
                break;

            default:
                /* It never should have come here... */
                break;
        }

        ((AvlNode *)bitree_data(grandchild))->factor = AVL_BALANCED;
        *node = grandchild;
    }

    return;
}

static void _rotate_right(BiTreeNode **node)
{
    BiTreeNode *right, *grandchild;

    right = bitree_right(*node);

    if (((AvlNode *)bitree_data(right))->factor == AVL_RGT_HEAVY)
    {
        /*
         * Perform an RR rotation.
         */
        bitree_right(*node) = bitree_left(right);
        bitree_left(right) = *node;
        ((AvlNode *)bitree_data(*node))->factor = AVL_BALANCED;
        ((AvlNode *)bitree_data(right))->factor = AVL_BALANCED;
        *node = right;
    }
    else
    {
        /*
         * Perform an RL roration.
         */
        grandchild = bitree_left(right);
        bitree_left(right) = bitree_right(grandchild);
        bitree_right(grandchild) = right;
        bitree_right(*node) = bitree_left(grandchild);
        bitree_left(grandchild) = *node;

        switch (((AvlNode *)bitree_data(grandchild))->factor)
        {
        case AVL_LFT_HEAVY:
            ((AvlNode *)bitree_data(*node))->factor = AVL_BALANCED;
            ((AvlNode *)bitree_data(right))->factor = AVL_RGT_HEAVY;
            break;

        case AVL_BALANCED:
            ((AvlNode *)bitree_data(*node))->factor = AVL_BALANCED;
            ((AvlNode *)bitree_data(right))->factor = AVL_BALANCED;
            break;

        case AVL_RGT_HEAVY:
            ((AvlNode *)bitree_data(*node))->factor = AVL_LFT_HEAVY;
            ((AvlNode *)bitree_data(right))->factor = AVL_BALANCED;
            break;

        default:
            /* It never should have come here... */
            break;
        }

        ((AvlNode *)bitree_data(grandchild))->factor = AVL_BALANCED;
        *node = grandchild;
    }
    
    return;

}

static void _destroy_left(BisTree *tree, BiTreeNode *node)
{
    BiTreeNode **position;

    /* Do not allow destruction of an empty tree. */
    if (bitree_size(tree) == 0)
        return;
    
    /* Determine where to destroy nodes. */
    if (node == NULL)
        position = &tree->root;
    else
        position = &node->left;

    /* Destroy the nodes */
    if(*position != NULL)
    {
        _destroy_left(tree, *position);
        _destroy_right(tree, *position);

        if (tree->destroy != NULL)
        {
            /* Call a user-defined function to free dynamically allocated data. */
            tree->destroy(((AvlNode *)bitree_data(*position))->data);
        }

        /* Free the AVL data in the node, then free the node itself. */
        free((*position)->data);
        free(*position);
        *position = NULL;

        /* Adjust the size of the tree to account for the destroyed node. */
        tree->size--;
    }

    return;
}

static void _destroy_right(BisTree *tree, BiTreeNode *node)
{
    BiTreeNode **position;

    /* Do not allow destruction of an empty tree. */
    if (bitree_size(tree) == 0)
        return;
    
    /* Determine where to destroy nodes. */
    if (node == NULL)
        position = &tree->root;
    else
        position = &node->right;

    /* Destroy the nodes */
    if (*position != NULL)
    {
        _destroy_left(tree, *position);
        _destroy_right(tree, *position);

        if (tree->destroy != NULL)
        {
            /* Call a user-defined function to free dynamically allocated data. */
            tree->destroy(((AvlNode *)bitree_data(*position))->data);
        }

        /* Free the AVL data in the node, then free the node itself. */
        free((*position)->data);
        free(*position);
        *position = NULL;

        /* Adjust the size of the tree to account for the destroyed node. */
        tree->size--;
    }

    return;
}

static int _insert(BisTree *tree, BiTreeNode **node, const void *data, int *balanced)
{
    AvlNode *avl_data;

    int cmpval, retval;

    /* Insert the data into the tree */
    if (bitree_is_eob(*node))
    {
        /* Handle insertion into an empty tree */

        if ((avl_data = (AvlNode *)malloc(sizeof(AvlNode))) == NULL)
            return -1;
        
        avl_data->factor = AVL_BALANCED;
        avl_data->hidden = 0;
        avl_data->data = (void *)data;

        return bitree_ins_left(tree, *node, avl_data);
    }
    else
    {
        /* Handle insertion into a tree that is not empty. */
        cmpval = tree->compare(data, ((AvlNode *)bitree_data(*node))->data);
        if (cmpval < 0)
        {
            /* Move to the left. */
            if (bitree_is_eob(bitree_left(*node)))
            {
                if ((avl_data = (AvlNode *)malloc(sizeof(AvlNode))) == NULL)
                    return -1;
                
                avl_data->factor = AVL_BALANCED;
                avl_data->hidden = 0;
                avl_data->data = (void *)data;

                if (bitree_ins_left(tree, *node, avl_data) != 0)
                    return -1;
                
                *balanced = 0;
            }
            else
            {
                if ((retval = _insert(tree, &bitree_left(*node), data, balanced)) != 0)
                {
                    return retval;
                }
            }

            /* Ensure that the tree remains balanced. */
            if(!(*balanced))
            {
                switch (((AvlNode*)bitree_data(*node))->factor)
                {
                case AVL_LFT_HEAVY:
                    
                    _rotate_left(node);
                    *balanced = 1;
                    break;
                
                case AVL_BALANCED:

                    ((AvlNode *)bitree_data(*node))->factor = AVL_LFT_HEAVY;
                    break;
                
                case AVL_RGT_HEAVY:

                    ((AvlNode *)bitree_data(*node))->factor = AVL_BALANCED;
                    *balanced = 1;
                }
            }
        }
        else if (cmpval > 0)
        {
            /* Move to the right. */
            if(bitree_is_eob(bitree_right(*node)))
            {
                if ((avl_data = (AvlNode *)malloc(sizeof(AvlNode))) == NULL)
                    return -1;
                
                avl_data->factor = AVL_BALANCED;
                avl_data->hidden = 0;
                avl_data->data = (void *)data;

                if (bitree_ins_right(tree, *node, avl_data) != 0)
                    return -1;
                
                *balanced = 0;
            }
            else
            {
                if ((retval = _insert(tree, &bitree_right(*node), data, balanced)) != 0)
                {
                    return retval;
                }
            }

            /* Ensure that the tree remains balanced. */            
            if(!(*balanced))
            {
                switch (((AvlNode *)bitree_data(*node))->factor)
                {
                case AVL_LFT_HEAVY:
                    
                    ((AvlNode *)bitree_data(*node))->factor = AVL_BALANCED;
                    *balanced = 1;
                    break;
                
                case AVL_BALANCED:

                    ((AvlNode *)bitree_data(*node))->factor = AVL_RGT_HEAVY;
                    break;

                case AVL_RGT_HEAVY:

                    _rotate_right(node);
                    *balanced = 1;
                    break;                    
                }
            }
        }
        else
        {
            /* Handle finding a copy of the data. */
            if (!((AvlNode *)bitree_data(*node))->hidden)
            {
                /* Do nothing since the data is in the tree and it not hidden. */
                return 1;
            }
            else
            {
                /* Insert the new data and mark it as not hidden. */
                if (tree->destroy != NULL)
                {
                    /* Destroy the hidden data since it is being replaced. */
                    tree->destroy(((AvlNode *)bitree_data(*node))->data);
                }

                ((AvlNode *)bitree_data(*node))->data = (void *)data;
                ((AvlNode *)bitree_data(*node))->hidden = 0;

                /* Do not rebalance because the tree structure is unchanged. */
                *balanced = 1;
            }
        }
    }

    return 0;
}

static int _hide(BisTree *tree, BiTreeNode *node, const void *data)
{
    int cmpval, retval;

    if (bitree_is_eob(node))
    {
        /* Return that the data was not found. */
        return -1;
    }

    cmpval = tree->compare(data, ((AvlNode *)bitree_data(node))->data);

    if (cmpval < 0)
    {
        /* Move to the left. */
        retval = _hide(tree, bitree_left(node), data);
    }
    else if (cmpval > 0)
    {
        /* Move to the right. */
        retval = _hide(tree, bitree_right(node), data);
    }
    else
    {
        /* Mark the node as hidden. */
        ((AvlNode *)bitree_data(node))->hidden = 1;
        retval = 0;
    }

    return retval;
}

static int _lookup(BisTree *tree, BiTreeNode *node, void **data)
{
    int cmpval, retval;

    if (bitree_is_eob(node))
    {
        /* Return that the data was not found. */
        return -1;
    }

    cmpval = tree->compare(*data, ((AvlNode *)bitree_data(node))->data);

    if (cmpval < 0)
    {
        /* Move to the left. */
        retval = _lookup(tree, bitree_left(node), data);
    }
    else if (cmpval > 0)
    {
        /* Move to the right. */
        retval = _lookup(tree, bitree_right(node), data);
    }
    else
    {
        if (!((AvlNode *)bitree_data(node))->hidden)
        {
            /* Pass back the data from the tree. */
            *data = ((AvlNode *)bitree_data(node))->data;
            retval = 0;
        }
        else
        {
            /* Return that the data was found. */
            return -1;
        }
    }

    return retval;
}

void bistree_init(BisTree *tree, int (*compare)(const void *key1, const void *key2),
                  void (*destroy)(void *data))
{
    /* Initialize the tree. */
    bitree_init(tree, destroy);
    tree->compare = compare;

    return;
}

void bistree_destroy(BisTree *tree)
{
    /* Destroy all nodes in the tree. */
    _destroy_left(tree, NULL);

    /* No operations are allowed now, but clear the structure as a precaution. */
    memset(tree, 0, sizeof(BisTree));

    return;
}

int bistree_insert(BisTree *tree, const void *data)
{
    int balanced = 0;

    return _insert(tree, &bitree_root(tree), data, &balanced);
}

int bistree_remove(BisTree *tree, const void *data)
{
    return _hide(tree, bitree_root(tree), data);
}

int bistree_lookup(BisTree *tree, void **data)
{
    return _lookup(tree, bitree_root(tree), data);
}