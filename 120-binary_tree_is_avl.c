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

/**
 * avl_tree_height - checks if a binary tree is a valid AVL Tree
 *
 * @tree: a pointer to the root node of the tree to check
 * Return: (int)
 */
int avl_tree_height(const binary_tree_t *tree)
{
	int left_h;
	int right_h;

	if (tree == NULL)
		return (0);
	left_h = avl_tree_height(tree->left);
	right_h = avl_tree_height(tree->right);
	return (left_h > right_h ? left_h + 1 : right_h + 1);
}

/**
 * binary_tree_is_avl_r - checks if a binary tree is a valid AVL Tree
 *
 * @tree: a pointer to the root node of the tree to check
 * Return: (int)
 */
int binary_tree_is_avl_r(const binary_tree_t *tree)
{
	int left_h, right_h;

	if (tree == NULL)
		return (1);

	left_h = avl_tree_height(tree->left);
	right_h = avl_tree_height(tree->right);
	if (abs(left_h - right_h) <= 1 && binary_tree_is_avl_r(tree->left) &&
		binary_tree_is_avl_r(tree->right))
		return (1);
	return (0);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 *
 * @tree: a pointer to the root node of the tree to check
 * Return: (int)
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (binary_tree_is_bst(tree) == 0)
		return (0);
	return (binary_tree_is_avl_r(tree));
}
