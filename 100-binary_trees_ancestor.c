#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_depth - Measures the depth of a binary tree
 * @tree: pointer to the root node
 *
 * Return: Always nothing
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL || !tree->parent)
		return (0);
	else
		return (binary_tree_depth(tree->parent) + 1);
}

/**
 * binary_trees_antecestor - finds the lowest common ancestor of two nodes
 *
 * @first: First node
 * @second: Second node
 * Return: pointer to the lowest common ancestor node
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t h_first, h_second;
	binary_tree_t *temp_f = (binary_tree_t *)first;
	binary_tree_t *temp_s = (binary_tree_t *)second;

	if (first == NULL || second == NULL)
		return (NULL);

	h_first = binary_tree_depth(first);
	h_second = binary_tree_depth(second);

	for (; h_first < h_second; h_second--)
		temp_s = temp_s->parent;
	for (; h_second < h_first; h_first--)
		temp_f = temp_f->parent;

	while (temp_f && temp_s)
	{
		if (temp_f == temp_s)
			return (temp_f);
		temp_f = temp_f->parent;
		temp_s = temp_s->parent;

	}
	return (NULL);

}
