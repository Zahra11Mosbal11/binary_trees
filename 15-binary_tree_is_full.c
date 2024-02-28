#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_is_full - checking if the binary tree is full
 * @tree: the tree to be evaluated
 * Return: 1 if the node is a leaf and returning the highest node;
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int l, r;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	l = binary_tree_is_full(tree->left);
	r = binary_tree_is_full(tree->right);

	return (l && r);
}
