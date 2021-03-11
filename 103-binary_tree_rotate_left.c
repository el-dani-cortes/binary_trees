#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 * @tree: pointer to the root node
 *
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp = NULL;

	temp = tree->right;
	if (tree->right != NULL)
	{
		temp->parent = tree->parent;
		if (temp->left)
		{
			tree->right = temp->left;
			temp->left->parent = tree;
		}
		else
			tree->right = NULL;
		temp->left = tree;
		tree->parent = temp;
	}
	return (temp);
}
