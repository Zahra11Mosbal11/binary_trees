#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
#include <limits.h>
/**
 * binary_tree_is_bst - binary tree is a valid Binary Search Tree
 * @tree: pointer to the tree
 * Return: 1 or 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (check_tree(tree, INT_MIN, INT_MAX));
}
/**
 * check_tree - check if is binary tree with int min max
 * @node: pointer to the tree
 * @min: the min
 * @max: max
 * Return: 1 or 0
 */
int check_tree(const binary_tree_t *node, int min, int max)
{
	if (node == NULL)
		return (1);
	if (node->n < min || node->n > max)
		return (0);
	return (check_tree(node->left, min, node->n - 1) &&
		check_tree(node->right, node->n + 1, max));
}
