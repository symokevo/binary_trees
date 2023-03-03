#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 *
 * @tree: a pointer to the root node of the tree to count the number of leaves
 * Return: (size_t)
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t nodeCount = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);
	nodeCount += binary_tree_leaves(tree->left);
	nodeCount += binary_tree_leaves(tree->right);
	return (nodeCount);
}
