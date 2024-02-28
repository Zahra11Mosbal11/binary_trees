#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 *binary_tree_nodes - Count the nodes that have at least one child
 *@tree: is a pointer to the root node of the tree to count the number of node
 *Return: 0 when tree is NULL or a recursive function call
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree != NULL && (tree->left != NULL || tree->right != NULL))
	{
		left = binary_tree_nodes(tree->left);
		right = binary_tree_nodes(tree->right);

		return (1 + (left + right));
	}
	return (0);
}
