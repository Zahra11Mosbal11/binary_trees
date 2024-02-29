#include "binary_trees.h"
#include "9-binary_tree_height.c"
/**
 *binary_tree_levelorder - level-order traversal
 *@tree: pointer to the tree
 *@func: pointer to a function
 *Return: nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height = 0;
	size_t count;
	binary_tree_t *_tree = (binary_tree_t *)tree;

	if (tree == NULL || func == NULL)
		return;

	height = binary_tree_height(tree);
	for (count = 0; count <= height + 1; count++)
		level(_tree, func, counter);
}
/**
 *level - print the nodes by level
 *@func: pointer to a functionn
 *@level: the level
 *@node: pointer to the node
 *Return: nothing
 */
void level(binary_tree_t *node, void (*func)(int), int level)
{
	if (node != NULL && func != NULL)
	{
		if (level == 1)
			func(node->n);
		if (level > 1)
		{
			level(node->left, func, level - 1);
			level(node->right, func, level - 1);
		}
	}
}
