#include "binary_trees.h"

/**
 * tree_root - returns the root of a given node
 *
 * @node: The node to get the root
 * Return: binary_tree_t*
 */
binary_tree_t *tree_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);
	if (node->parent == NULL)
		return ((binary_tree_t *)(node));
	return (tree_root(node->parent));
}

/**
 * trees_ancestor - finds the lowest common ancestor of two nodes
 *
 * @node: a pointer to the current node
 * @first: a pointer to the first node
 * @second: second is a pointer to the second node
 * Return: (binary_tree_t*)
 */
binary_tree_t *lowest_common_ancestor(binary_tree_t *node,
									  const binary_tree_t *first,
									  const binary_tree_t *second)
{
	binary_tree_t *left_tree;
	binary_tree_t *right_tree;

	if (node == NULL)
		return (NULL);
	else if (node == first || node == second)
		return (node);

	left_tree = lowest_common_ancestor(node->left, first, second);
	right_tree = lowest_common_ancestor(node->right, first, second);

	if (left_tree != NULL && right_tree != NULL)
		return (node);
	else if (left_tree != NULL)
		return (left_tree);
	else
		return (right_tree);
	return (NULL);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *
 * @first: a pointer to the first node
 * @second: second is a pointer to the second node
 * Return: (binary_tree_t*)
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	binary_tree_t *tree;
	binary_tree_t *tree2;

	if (first == NULL || second == NULL)
		return (NULL);

	tree = tree_root(first);
	tree2 = tree_root(second);

	if (tree != tree2)
		return (NULL);

	return (lowest_common_ancestor(tree, first, second));
}
