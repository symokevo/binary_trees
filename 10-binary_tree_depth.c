#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 *
 * @tree: a pointer to the node to measure the depth
 * Return: (size_t)
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t parentHeight = 0;

	if (tree == NULL)
		return (0);

	parentHeight = binary_tree_depth(tree->parent);
	if (tree->parent == NULL)
		parentHeight -= 1;
	return (parentHeight + 1);
}
