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
 * print_given_level - Prints the data with the same level
 * @tree: pointer to the root node
 * @func: pointer to a function to call for each node
 * @level: level of the node.
 *
 * Return: Always nothing
 */
void print_given_level(const binary_tree_t *tree, size_t level,
		       void (*func)(int))
{
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		print_given_level(tree->left, level - 1, func);
		print_given_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - Prints the data through a binary tree
 * using level-order traversal.
 * @tree: pointer to the root node
 * @func: pointer to a function to call for each node
 *
 * Return: Always nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t d, height;

	if (tree == NULL || func == NULL)
		return;
	height = binary_tree_height(tree);
	for (d = 1; d <= height + 1; d++)
		print_given_level(tree, d, func);
}
