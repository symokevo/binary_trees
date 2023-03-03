#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the height
 * Return: (size_t)
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t leftHeight = 0;
	size_t rightHeight = 0;
	size_t maxHeight;

	if (tree == NULL)
		return (0);

	leftHeight = binary_tree_height(tree->left);
	rightHeight = binary_tree_height(tree->right);
	maxHeight = leftHeight > rightHeight ? leftHeight : rightHeight;
	if (tree->left == NULL && tree->right == NULL)
		maxHeight -= 1;
	return (maxHeight + 1);
}
