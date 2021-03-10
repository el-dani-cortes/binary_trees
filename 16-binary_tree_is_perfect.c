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
 * u_pow - calculate power of a number
 * @x: base number
 * @y: exponent number
 * Return: power of x
 */
size_t u_pow(size_t x, size_t y)
{
	size_t result = 1;

	while (y > 0)
	{
		result *= x;
		y--;
	}
	return (result);
}

/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree of check
 *
 * Return: 1 if is perfect and 0 if not
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t n_spect, n_real, height;

	if (tree == NULL)
		return (0);
	height = binary_tree_height(tree);
	n_spect = u_pow(2, height + 1) - 1;
	n_real = binary_tree_size(tree);
	if (n_spect == n_real)
		return (1);
	return (0);

}
