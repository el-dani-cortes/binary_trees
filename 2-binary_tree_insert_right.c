#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: parent of node
 * @value: number to add
 *
 * Return: pointer to the created node or NULL on failure
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(binary_tree_t));
	if (parent == NULL || new_node == NULL)
	{
		return (NULL);
	}
	else
	{
		if (parent->right != NULL)
		{
			new_node->right = parent->right;
			parent->right->parent = new_node;
		}
		else
		{
			new_node->right = NULL;

		}
		new_node->parent = parent;
		new_node->n = value;
		parent->right = new_node;
		new_node->left = NULL;

	}
	return (new_node);
}
