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
 * binary_tree_height - Measures the height of a binary tree
 * @tree: pointer to the root node
 *
 * Return: balance type size_t
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int h_left = 0, h_right = 0, height;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		h_left = binary_tree_height(tree->left) + 1;
	if (tree->right != NULL)
		h_right = binary_tree_height(tree->right) + 1;

	height = h_left - h_right;
	return (height);
}

/**
 * binary_tree_is_full - check if tree is full
 * @tree: pointer to tree
 *
 * Return: 1 if tree is full otherside 0
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if ((tree->left) && (tree->right))
		return (binary_tree_is_full(tree->left) *
			binary_tree_is_full(tree->right));

	return (0);

}

/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree of check
 *
 * Return: 1 if is perfect and 0 if not
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int isFull, isBalance;

	isFull = binary_tree_is_full(tree);
	isBalance = binary_tree_balance(tree);
	if (isFull == 1 && isBalance == 0)
		return (1);
	return (0);

}
