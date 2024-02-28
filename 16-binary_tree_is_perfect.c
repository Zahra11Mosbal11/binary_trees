#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_is_perfect - check if a binary tree is perfect
 * @tree: pointer to root node of tree to check
 * Return: 1 if binary tree is perfect, else return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height, size;

	if (tree == NULL)
		return (0);

	height = _binary_tree_height(tree);
	size = binary_tree_size(tree);

	return ((size == (1 << height) - 1));
}
/**
 * binary_tree_size - to get the size
 *@tree: the tree
 *Return: the size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size, right_size;

	if (tree == NULL)
		return 0;

	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);

	return (1 + left_size + right_size);
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
