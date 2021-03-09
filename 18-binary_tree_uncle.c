#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node
 * @node: pointer to the node
 *
 * Return: pointer to the sibling node or NULL if node has not sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);
	if (node->parent)
	{
		if (node->parent->left == node)
			return (node->parent->right);
		else if (node->parent->right == node)
			return (node->parent->left);
		else
			return (NULL);
	}
	return (NULL);
}
/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: pointer to the node
 *
 * Return: pointer to the uncle node or NULL if node has not uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *uncle = NULL;

	if (node == NULL)
		return (NULL);
	if (node->parent)
	{
		uncle = binary_tree_sibling(node->parent);
		return (uncle);
	}
	return (NULL);
}
