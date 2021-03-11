#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 *@tree: ouble pointer to the root node of the BST to insert the value
 *@value: value to store in the node to be inserted
 *
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
        bst_t *walk = NULL;

        walk = *tree;
        if (walk == NULL)
        {
                *tree = binary_tree_node(NULL, value);
                return (*tree);
        }
        while (walk != NULL)
        {
                if (walk->n > value)
                {
                        if (walk->left == NULL)
                        {
                                walk->left = binary_tree_node(walk, value);
                                return (walk->left);
                        }
                        walk = walk->left;
                }
                else if (walk->n < value)
                {
                        if (walk->right == NULL)
                        {
                                walk->right = binary_tree_node(walk, value);
                                return (walk->right);
                        }
                        walk = walk->right;
                }
                else if (walk->n == value)
                        return (NULL);
        }
        return (NULL);
}
