#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_depth - measure the depth of a node in a binary tree.
 * Depth is measured from root parent node going down.
 * @tree: pointer to node to measure depth of
 * Return: depth of tree from given node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL || tree->parent == NULL)
		return (0);

	return (binary_tree_depth(tree->parent) + 1);
}
