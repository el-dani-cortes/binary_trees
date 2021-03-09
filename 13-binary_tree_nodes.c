#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child
 * @tree: pointer to the roo node of the tree
 *
 * Return: number of nodes with at least 1 child or 0 if tree is NULL
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t node = 0;

	if (tree == NULL)
	{
		return (0);
	}
	node += binary_tree_nodes(tree->left);
	node += binary_tree_nodes(tree->right);

	if (tree->left != NULL || tree->right != NULL)
		node++;




	return (node);
}
