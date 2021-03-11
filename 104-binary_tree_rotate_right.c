#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 * @tree: pointer to the root node
 *
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *temp = NULL;

	if (tree == NULL)
		return (tree);
	temp = tree->left;
	temp->parent = tree->parent;
	if (temp->right)
	{
		tree->left = temp->right;
		temp->right->parent = tree;
	}
	else
		tree->left = NULL;
	temp->right = tree;
	tree->parent = temp;
	return (temp);
}
