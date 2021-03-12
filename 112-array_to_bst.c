#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * array_to_bst - that builds a Binary Search tree
 * @array: is a pointer to the first element of the array
 * @size: is the number of element in the array
 *
 * Return: 0 on success, error code on failure
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *trees = NULL, *temp, *temp2 = NULL, *new_node = NULL;
	size_t i = 0;

	for (i = 0; i < size; i++)
	{
		new_node = malloc(sizeof(bst_t));
		if (new_node == NULL)
			return (NULL);
		new_node->n = array[i];
		new_node->left = NULL;
		new_node->right = NULL;
		if (trees == NULL)
		{
			new_node->parent = NULL;
			trees = new_node;
		}
		else
		{
			temp = trees;
			while (temp)
			{
				temp2 = temp;
				if (new_node->n < temp->n)
					temp = temp->left;
				else
					temp = temp->right;
			}
			if (temp2->n > new_node->n)
			{
				temp2->left = new_node;
				new_node->parent = temp2;
			}
			else
			{
				temp2->right = new_node;
				new_node->parent = temp2;
			}
		}
	}
	return (trees);
}
