#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * maxValue - find the max value of a bianry tree
 * @greater: num more big
 * @lesser: num less
 * @tree: is a pointer to the root node
 * Return: max value
 */

int maxValue(const binary_tree_t *tree, int lesser, int greater)
{
	if (tree == NULL)
		return (1);
	if (tree->n >= greater || tree->n <= lesser)
		return (0);
	return ((maxValue(tree->left, lesser, tree->n)) &&
		(maxValue(tree->right, tree->n, greater)));
}


/**
 * binary_tree_is_bst - checks if a binary tree is a valid bst
 * @tree: is a pointer to the roo node
 * Return: 1 if tree is valid bst, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (maxValue(tree, INT_MIN, INT_MAX));

}
