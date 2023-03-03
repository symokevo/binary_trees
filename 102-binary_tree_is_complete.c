#include "binary_trees.h"

/**
 * count_nodes - returns number of nodes in a tree
 *
 * @tree: A pointer to the tree to be counted
 * Return: (int)
 */
int count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * is_complete_tree - checks if a binary tree is complete
 *
 * @tree: a pointer to the root node of the tree to check
 * @index: The index of the node
 * @node_count: The total number of nodes in the tree
 * Return: (int)
 */
int is_complete_tree(const binary_tree_t *tree, int index, int node_count)
{
	if (tree == NULL)
		return (1);

	if (index >= node_count)
		return (0);

	return (is_complete_tree(tree->left, 2 * index + 1, node_count) &&
			is_complete_tree(tree->right, 2 * index + 2, node_count));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 *
 * @tree: a pointer to the root node of the tree to check
 * Return: (int)
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_complete_tree(tree, 0, count_nodes(tree)));
}
