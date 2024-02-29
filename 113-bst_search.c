#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * bst_search - Searches for a value in a Binary Search Tree
 * @tree: is a pointer to the root node of the BST to search
 * @value: is the value to search in the tree
 * Return: a pointer to the node containing a value equals to value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);
	if (tree->n == value)
		return ((void *)tree);
	if (tree->n > value)
		return (bst_search(tree->left, value));
	if (tree->n < value)
		return (bst_search(tree->right, value));
	return (NULL);
}
