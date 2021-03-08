#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_delete - delete all tree
 * @tree: is pointer to the root
 * Return: Nothing
 */

void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *temp = NULL;
	binary_tree_t *freedom = NULL;

	temp = tree;
	if (tree != NULL)
	{
		if (temp->left != NULL)
			binary_tree_delete(temp->left);
		else if (temp->right != NULL)
			binary_tree_delete(temp->right);
		else
		{
			freedom = temp;
			temp = temp->parent;
			free(freedom);
			binary_tree_delete(temp);
		}
	}
	return;
}
