#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array
 *
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of element in the array
 * Return: (bst_t*)
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *root;

	if (array == NULL || size == 0)
		return (NULL);

	root = NULL;
	for (i = 0; i < size; i++)
	{
		bst_insert(&root, *(array + i));
	}
	return (root);
}
