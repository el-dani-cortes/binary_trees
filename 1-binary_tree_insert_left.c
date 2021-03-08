#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: parent of node
 * @value: number to add
 * Return: pointer to the created node or NULL on failure
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(binary_tree_t));
	if (parent == NULL || new_node == NULL)
	{
		return (NULL);
	}
	else
	{
		if (parent->left != NULL)
		{
			new_node->parent = parent;
			new_node->left = parent->left;
			parent->left->parent = new_node;
			parent->left = new_node;
			new_node->right = NULL;
		}
		else
		{
			new_node = binary_tree_node(parent, value);
			parent->left = new_node;
		}
	}
	return (new_node);
}
