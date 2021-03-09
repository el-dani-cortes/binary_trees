#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Create a new node
 *
 * @parent: Pointer to the parent node
 * @value: value to insert as data in the node
 *
 * Return: pointer to new node created or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
        binary_tree_t *new_node = NULL;

        new_node = malloc(sizeof(binary_tree_t));
        if (new_node == NULL)
                return (NULL);
        new_node->parent = parent;
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->n = value;
        return (new_node);
}
