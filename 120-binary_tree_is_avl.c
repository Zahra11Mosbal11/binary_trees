#include "binary_trees.h"
#include "limits.h"
/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl(tree, INT_MIN, INT_MAX));
}
/**
 * is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @low: The value of the smallest node visited thus far.
 * @height: The value of the largest node visited this far.
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int is_avl(const binary_tree_t *tree, int low, int height)
{
	size_t l, r, dif;

	if (tree != NULL)
	{
		if (tree->n < low || tree->n > height)
			return (0);
		l = tree_height(tree->left);
		r = tree_height(tree->right);
		dif = l > r ? l - r : r - l;
		if (dif > 1)
			return (0);
		return (is_avl(tree->left, low, tree->n - 1) &&
			is_avl(tree->right, tree->n + 1, height));
	}
	return (1);
}
/**
 * tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (tree)
	{
		l = tree->left ? 1 + tree_height(tree->left) : 1;
		r = tree->right ? 1 + tree_height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}
