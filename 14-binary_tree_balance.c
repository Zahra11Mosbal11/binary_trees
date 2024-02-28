#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_balance - measure the balance factor of a binary tree
 * @tree: pointer to root node of tree to measure
 * Return: balance factor left height minus right height, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	left = _binary_tree_height(tree->left);
	right = _binary_tree_height(tree->right);

	return (left - right);
}
/**
 * _binary_tree_height - Measure the height
 * of a binary tree from a given node
 * @tree: pointer to node of tree to measure
 * Description: Edited to work with balance factor function
 * Return: height of tree or -1 if NULL
*/
int _binary_tree_height(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (-1);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	left = _binary_tree_height(tree->left) + 1;
	right = _binary_tree_height(tree->right) + 1;

	if (left > right)
		return (left);
	else
		return (right);
}
