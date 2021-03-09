#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: pointer to the root node
 *
 * Return: balance type size_t
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t h_left = 0, h_right = 0, height;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		h_left = binary_tree_balance(tree->left) + 1;
	if (tree->right != NULL)
		h_right = binary_tree_balance(tree->right) + 1;
	height = (h_left - h_right);
	return (height);
}
