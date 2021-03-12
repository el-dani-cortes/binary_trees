#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * bst_search - function that searches for a value
 * @tree: pointer to the root
 * @value: is the value to search
 * Return: pointer to the root node of the BST to search
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *temp = NULL;

	if (!tree)
		return (NULL);
	if (tree->n == value)
	{
		return ((bst_t *)tree);
	}
	else if (tree->n > value)
	{
		temp = bst_search(tree->left, value);
	}
	else
	{
		temp = bst_search(tree->right, value);
	}
	return (temp);
}
