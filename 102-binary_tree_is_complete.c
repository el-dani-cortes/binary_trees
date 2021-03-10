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
/**
 * is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node
 * @index: index level of the node
 * @size: number of nodes in the binary tree
 *
 * Return: true if is complete and false if not or if tree is NULL
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t size)
{
	if (tree == NULL)
		return (1);
	if (index >= size)
		return (0);
	return (is_complete(tree->left, 2 * index + 1, size) &&
		is_complete(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node
 *
 * Return: 1 if is complete and 0 if not or if tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size, index = 0;

	size = binary_tree_size(tree);
	return (is_complete(tree, index, size));
}
