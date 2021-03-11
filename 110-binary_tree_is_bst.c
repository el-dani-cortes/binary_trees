#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

int maxValue(const binary_tree_t *tree)
{
	int res;
	int lres;
	int rres;

	if (tree == NULL)
		return (-1000000);
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
 *
 *
 */
int minValue(const binary_tree_t *tree)
{
	int rest, lres, rres;

	if (tree == NULL)
		return (1000000);
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
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return(1);
	if (tree->left != NULL && maxValue(tree->left) > tree->n)
	{
		return (0);
	}
	if (tree->right != NULL && minValue(tree->right) < tree->n)
	{
		return (0);
	}
	if (!binary_tree_is_bst(tree->left) || !binary_tree_is_bst(tree->right))
		return (0);
	return (1);

}
