#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the size
 * Return: (size_t)
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t leftNodes = 0;
	size_t rightNodes = 0;
	size_t nodeCount;

	if (tree == NULL)
		return (0);

	leftNodes = binary_tree_size(tree->left);
	rightNodes = binary_tree_size(tree->right);
	nodeCount = leftNodes + rightNodes;
	return (nodeCount + 1);
}
