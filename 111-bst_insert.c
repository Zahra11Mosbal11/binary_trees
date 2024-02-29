#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
#include "1-binary_tree_insert_left.c"
#include "2-binary_tree_insert_right.c"
/**
 * bst_insert - inserts a value in a Binary Search Tree
 *
 *@tree: double pointer to the root node of the BST to insert the value
 *@value: value to store in the node to be inserted
 *
 * Return: a pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree == NULL || *tree == NULL)
		return (*tree = binary_tree_node(NULL, value));
	if ((*tree)->n == value)
		return (NULL);
	if ((*tree)->n > value)
	{
		if ((*tree)->left == NULL)
			return (binary_tree_insert_left(*tree, value));
		return (bst_insert(&((*tree)->left), value));
	}
	if ((*tree)->n < value)
	{
		if ((*tree)->right == NULL)
			return (binary_tree_insert_right(*tree, value));
		return (bst_insert(&((*tree)->right), value));
	}
	return (NULL);
}
