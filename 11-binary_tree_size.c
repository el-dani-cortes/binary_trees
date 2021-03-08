#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: pointer to the root node
 *
 * Return: Always nothing
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t h_left = 0, h_right = 0, size = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		h_left = binary_tree_size(tree->left);
	if (tree->right != NULL)
		h_right = binary_tree_size(tree->right);
	size = h_left + h_right + 1;
	return (size);
}
