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
	return (maxHeight + 1);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the balance factor
 * Return: (int)
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int leftHeight;
	int rightHeight;

	if (tree == NULL)
		return (0);

	leftHeight = binary_tree_height(tree->left);
	rightHeight = binary_tree_height(tree->right);

	return (leftHeight - rightHeight);
}
