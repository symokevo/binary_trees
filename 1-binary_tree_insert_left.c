#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 *
 * @parent: a pointer to the node to insert the left-child in
 * @value: the value to store in the new node
 * Return: binary_tree_t* or NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (parent == NULL || node == NULL)
	{
		free(node);
		return (NULL);
	}

	node->left = NULL;
	node->right = NULL;
	node->parent = parent;
	node->n = value;

	if (parent->left)
	{
		node->left = parent->left;
		parent->left->parent = node;
	}
	parent->left = node;
	return (node);
}
