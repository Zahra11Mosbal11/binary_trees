#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_size - measure the size of a binary tree from a given node
 * @tree: root node of tree to measure from
 * Return: size of tree from a given node
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_size(tree->left);
	right_height = binary_tree_size(tree->right);

	return (1 + (left_height + right_height));
}
