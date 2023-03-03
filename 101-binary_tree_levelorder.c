#include "binary_trees.h"

/**
 * pop - removes the item in the front of the queue
 *
 * @queue: A pointer to the head of the queue
 * Return: (binary_queue_t*)
 */
binary_queue_t *pop(binary_queue_t **queue)
{
	binary_queue_t *node;

	if (queue == NULL)
		return (NULL);
	node = malloc(sizeof(binary_queue_t));
	if (node == NULL)
		return (NULL);
	node->data = (*queue)->data;
	node->next = (*queue)->next;
	free(*queue);
	(*queue) = node->next;
	return (node);
}

/**
 * push - push an item into the queue
 *
 * @queue: A pointer to the head of the queue
 * @data: The item to be pushed into the queue
 */
void push(binary_queue_t **queue, binary_tree_t *data)
{
	binary_queue_t *node = malloc(sizeof(binary_queue_t));
	binary_queue_t *tail;

	if (node == NULL)
		return;
	node->data = data;
	node->next = NULL;
	if (*queue == NULL)
		*queue = node;
	else
	{
		tail = *queue;
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = node;
	}
}

/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
 *
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_queue_t *queue = NULL, *node;

	if (tree == NULL || func == NULL)
		return;

	push(&queue, (binary_tree_t *)tree);
	while (queue)
	{
		func(queue->data->n);
		node = pop(&queue);
		if (node)
		{
			if (node->data->left != NULL)
				push(&queue, node->data->left);
			if (node->data->right != NULL)
				push(&queue, node->data->right);
			free(node);
		}
	}
}
