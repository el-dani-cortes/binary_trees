#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * maxValue - find the max value of a bianry tree
 * @tree: is a pointer to the root node
 * Return: max value
 */

int maxValue(const binary_tree_t *tree)
{
	int min_number = -32768;
	int res;
	int lres;
	int rres;

	if (tree == NULL)
		return (min_number);
	res = tree->n;
	lres = maxValue(tree->left);
	rres = maxValue(tree->right);

	if (lres > res)
		res = lres;
	if (rres > res)
		res = rres;

	return (res);
}
/**
 * minValue - find the min value of a binary tree
 * @tree: is a pointer to the root node
 * Return: min value
 */
int minValue(const binary_tree_t *tree)
{
	int max_number = 32767;
	int rest, lres, rres;

	if (tree == NULL)
		return (max_number);
	rest = tree->n;
	lres = minValue(tree->left);
	rres = minValue(tree->right);
	if (lres < rest)
		rest = lres;
	if (rres < rest)
		rest = rres;
	return (rest);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid bst
 * @tree: is a pointer to the roo node
 * Return: 1 if tree is valid bst, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int l_res, r_res;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL && maxValue(tree->left) > tree->n)
	{
		return (0);
	}
	if (tree->right != NULL && minValue(tree->right) < tree->n)
	{
		return (0);
	}
	if (tree->left)
		l_res = binary_tree_is_bst(tree->left);
	if (tree->right)
		r_res = binary_tree_is_bst(tree->right);
	if (!l_res || !r_res)
		return (0);
	return (1);

}
