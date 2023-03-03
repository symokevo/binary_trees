#include "binary_trees.h"

/**
 * height - checks if a binary tree is a valid AVL Tree
 *
 * @tree: a pointer to the root node of the tree to check
 * Return: (int)
 */
int height(const avl_t *tree)
{
	int left_h;
	int right_h;

	if (tree == NULL)
		return (0);
	left_h = height(tree->left);
	right_h = height(tree->right);
	return (left_h > right_h ? left_h + 1 : right_h + 1);
}

/**
 * balanceFactor - returns the balance factor
 *
 * @tree: pointer to the root of the tree to be balanced
 * Return: int
 */
int balanceFactor(const avl_t *tree)
{
	if (tree == NULL)
		return (0);
	return (height(tree->left) - height(tree->right));
}

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

/**
 * balance_tree - balances the tree
 *
 * @root: A pointer to the root
 * @value: inserted value
 * Return: bst_t*
 */
bst_t *balance_tree(bst_t *root, int value)
{
	int bf;

	bf = balanceFactor(root);
	if (bf > 1 && value < root->left->n)
		return (binary_tree_rotate_right(root));

	if (bf < -1 && value > root->right->n)
		return (binary_tree_rotate_left(root));

	if (bf > 1 && value > root->left->n)
	{
		root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}

	if (bf < -1 && value < root->right->n)
	{
		root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}
	return (root);
}
/**
 * avl_insert -  inserts a value in an AVL Tree
 *
 * @tree: a double pointer to the root node of the AVL tree for
 * inserting the value
 * @value: the value to store in the node to be inserted
 * Return: avl_t*
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *root = *tree, *node;

	node = bst_insert(tree, value);
	if (root == NULL)
		return (node);
	*tree = balance_tree(root, value);
	return (node);
}
