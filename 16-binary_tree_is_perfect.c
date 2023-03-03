#include "binary_trees.h"

/**
 * tree_depth - Returns the depth of the tree
 *
 * @tree: A pointer to the root of the tree to be checked
 * Return: (int)
 */
int tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (tree_depth(tree->left) + 1);
}

/**
 * is_perfect_tree -  checks if a binary tree is perfect
 *
 * @tree: a pointer to the root node of the tree to check
 * @depth: the depth of the tree
 * @level: the level of the node
 * Return: (int)
 */
int is_perfect_tree(const binary_tree_t *tree, int depth, int level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (depth == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_tree(tree->left, depth, level + 1) &&
			is_perfect_tree(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: a pointer to the root node of the tree to check
 * Return: (int)
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_perfect_tree(tree, tree_depth(tree), 0));
}
