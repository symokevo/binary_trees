#include "binary_trees.h"

/**
 * bst_minimum - finds the minimum value in the tree
 *
 * @tree: tree to be traversed
 * Return: (bst_t*)
 */
bst_t *bst_minimum(const bst_t *tree)
{
	bst_t *node;
	node = (bst_t *)tree;

	while (node->left != NULL)
	{
		node = node->left;
	}
	return (node);
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 *
 * @root: a pointer to the root node of the tree where you will remove a node
 * @value: is the value to remove in the tree
 * Return: (bst_t*)
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp;

	if (root == NULL)
		return (root);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			tmp = root->right;
			free(root);
			return (tmp);
		}
		else if (root->right == NULL)
		{
			tmp = root->left;
			free(root);
			return (tmp);
		}

		tmp = bst_minimum(root->right);
		root->n = tmp->n;
		root->right = bst_remove(root->right, tmp->n);
	}
	return (root);
}
