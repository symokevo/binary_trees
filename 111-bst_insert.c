#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 *
 * @tree: a double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 * Return: (bst_t*)
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *parent = NULL, *node, *new_node;

	node = *tree;
	while (node != NULL)
	{
		parent = node;
		if (value == node->n)
			return (NULL);
		else if (value < node->n)
			node = node->left;
		else
			node = node->right;
	}

	new_node = binary_tree_node(parent, value);
	if (parent == NULL)
		*tree = new_node;
	else if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;
	return (new_node);
}
