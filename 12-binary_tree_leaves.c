#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	int num = 0;

	if (tree->left != NULL)
		num++;
	if (tree->right != NULL)
		num++;
	if (tree->left == NULL && tree->right == NULL)
		num = 1;
	return (num);
}
