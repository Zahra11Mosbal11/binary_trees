#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array
 *
 *@array: pointer to the first element of the array to be converted
 *@size: size of array
 *
 * Return: a pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i = 0;
	bst_t *root;

	root = NULL;
	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);
	return (root);
}
