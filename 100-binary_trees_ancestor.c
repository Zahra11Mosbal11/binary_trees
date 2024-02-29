#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_trees_ancestor - function that checks an ancestor
 * @first: First node
 * @second: Second node
 * Return: the node of the ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *node1, *node2;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}
	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	node1 = first->parent;
	node2 = second->parent;
	if (node1 == NULL || first == node2 || (!node1->parent && node2))
	{
		return (binary_trees_ancestor(first, node2));
	}
	else if (node2 == NULL || node1 == second || (!node2->parent && node1))
	{
		return (binary_trees_ancestor(node1, second));
	}
	return (binary_trees_ancestor(node1, node2));
}
