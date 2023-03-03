#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 *
 * @tree: a pointer to the root node of the tree to rotate
 * Return: (binary_tree_t*)
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *node, *parent, *left, *right, *head;

	if (tree == NULL)
		return (NULL);

	node = tree;
	head = tree;
	while (node != NULL)
	{
		if (node->left)
		{
			parent = node->parent;
			right = node->left->right;
			left = node->left;
			left->right = node;
			node->parent = left;
			left->parent = parent;
			node->left = right;
			if (right != NULL)
				right->parent = node;
			if (parent && parent->parent)
			{
				if (parent->parent->left == parent)
					parent->parent->left = left;
				else
					parent->parent->right = left;
			}
			else
				head = left;
		}
		node = node->left;
	}
	return (head);
}
