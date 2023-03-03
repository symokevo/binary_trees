#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 *
 * @tree: a pointer to the root node of the tree to rotate
 * Return: (binary_tree_t*)
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *node, *parent, *left, *right, *head;

	if (tree == NULL)
		return (NULL);

	node = tree;
	head = tree;
	while (node != NULL)
	{
		parent = node->parent;
		if (node->right)
		{
			left = node->right->left;
			right = node->right;
			right->left = node;
			node->parent = right;
			right->parent = parent;
			node->right = left;
			if (left != NULL)
				left->parent = node;
			if (parent && parent->parent)
			{
				if (parent->parent->left == parent)
					parent->parent->left = right;
				else
					parent->parent->right = right;
			}
			else
				head = right;
		}
		node = node->right;
	}
	return (head);
}
