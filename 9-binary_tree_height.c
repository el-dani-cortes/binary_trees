#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * max - Find the maximum number between two numbers
 * @num1: number 1
 * @num2: number 2
 *
 * Return: maximum number
 */
size_t max(size_t num1, size_t num2)
{
	if (num1 > num2)
		return (num1);
	else if (num1 < num2)
		return (num2);
	else
		return (num1);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: pointer to the root node
 *
 * Return: Always nothing
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h_left = 0, h_right = 0, height;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		h_left = binary_tree_height(tree->left) + 1;
	if (tree->right != NULL)
		h_right = binary_tree_height(tree->right) + 1;
	height = max(h_left, h_right);
	return (height);
}
