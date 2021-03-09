#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{

	binary_tree_t *root;
	int balance;

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	binary_tree_insert_right(root->left, 54);
	binary_tree_insert_right(root, 128);
	root->left->left = binary_tree_node(root->left, 10);
	root->right->left = binary_tree_node(root->right, 10);
	root->right->right->left = binary_tree_node(root->right->right, 10);
	root->right->right->right = binary_tree_node(root->right->right, 10);
	binary_tree_print(root);
	balance = binary_tree_balance(root);
	printf("Balance of %d: %+d\n", root->n, balance);
	return (0);
}