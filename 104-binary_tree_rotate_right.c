#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 *binary_tree_rotate_right - rotate to the left
 *@tree: pointer to the tree
 *Return: the new root
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tmpe, *node;

	tmpe = NULL;
	if (tree == NULL || tree->left == NULL)
		return (NULL);
	if (tree->left->right != NULL)
		tmpe = tree->left->right;
	node = tree->left;
	tree->left->right = tree;
	tree->parent = tree->left;
	tree->left->parent = NULL;
	tree->left = tmpe;
	if (tmpe != NULL)
		tmpe->parent = tree;
	return (node);
}
