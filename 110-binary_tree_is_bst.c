#include "binary_trees.h"

/**
 * in_order_traversal - traverse in order
 *
 * @tree: a pointer to the root node
 * @list: a pointer to the list
 */
void in_order_traversal(const binary_tree_t *tree, linked_list_t **list)
{
	linked_list_t *node;

	if (tree == NULL)
		return;

	in_order_traversal(tree->left, list);
	node = malloc(sizeof(linked_list_t));
	if (node == NULL)
		return;
	node->n = tree->n;
	node->next = NULL;
	node->tail = NULL;
	if (*list == NULL)
	{
		*list = node;
		(*list)->tail = node;
	}
	else
	{
		(*list)->tail->next = node;
		(*list)->tail = node;
	}
	in_order_traversal(tree->right, list);
}
/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 *
 * @tree: a pointer to the root node of the tree to check
 * Return: (int)
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	linked_list_t **list;
	linked_list_t *node, *tmp;
	int is_bst = 1;

	if (tree == NULL)
		return (0);

	list = calloc(sizeof(linked_list_t *), 1024);
	if (list == NULL)
		return (0);
	in_order_traversal(tree, list);
	node = *list;
	while (node != NULL)
	{
		if (node->next)
		{
			if (node->n >= node->next->n)
				is_bst = 0;
		}
		tmp = node->next;
		free(node);
		node = tmp;
	}
	free(list);
	return (is_bst);
}
