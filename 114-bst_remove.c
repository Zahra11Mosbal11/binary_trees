#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
bst_t *successor(bst_t *root);
bst_t *_delete(bst_t *root, bst_t *node);
bst_t *recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: is a pointer to the root node of the tree where you will remove
 * @value: is the value to remove in the tree
 * Return: a pointer to the new root node of the tree after removing
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (recursive(root, root, value));
}
/**
 * recursive - Removes a node from a binary search tree recursively.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @node: A pointer to the current node in the BST.
 * @value: The value to remove from the BST.
 * Return: A pointer to the root node after deletion.
 */
bst_t *recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (_delete(root, node));
		if (node->n > value)
			return (recursive(root, node->left, value));
		return (recursive(root, node->right, value));
	}
	return (NULL);
}
/**
 * _delete - Deletes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to delete from the BST.
 * Return: A pointer to the new root node after deletion.
 */
bst_t *_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *sucsor = NULL;

	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}
	sucsor = successor(node->right);
	node->n = sucsor->n;

	return (_delete(root, sucsor));
}
/**
 * successor - Returns the minimum value of a binary search tree.
 * @root: A pointer to the root node of the BST to search.
 * Return: The minimum value in @tree.
 */
bst_t *successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}
