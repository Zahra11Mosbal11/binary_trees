#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 *binary_tree_rotate_left - rotate to the left
 *@tree: pointer to the tree
 *Return: the new root
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmpe, *node;

	tmpe = NULL;
	if (tree == NULL || tree->right == NULL)
		return (NULL);
	if (tree->right->left != NULL)
		tmpe = tree->right->left;
	node = tree->right;
	tree->right->left = tree;
	tree->parent = tree->right;
	tree->right->parent = NULL;
	tree->right = tmpe;
	if (tmpe != NULL)
		tmpe->parent = tree;
	return (node);
}
