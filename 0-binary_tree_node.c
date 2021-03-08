#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/* Original code from http://stackoverflow.com/a/13755911/5184480 */

/**
 * binary_tree_t *binary_tree_node - Create a new node
 *
 * @parent: Pointer to the parent node
 * @value: value to insert as data in the node
 *
 * Return: length of printed tree after process
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(binary_tree_t));
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->n = value;
	return new_node;
}
