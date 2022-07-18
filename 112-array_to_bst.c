#include "binary_trees.h"

/**
 * array_to_bst - Creates a BST from an array
 * @array: Array of integers
 * @size: Size of the array
 *
 * Return: Pointer to the root of the BST or NULL if it fails
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i;

	if (!array || !size)
		return (NULL);
	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);
	return (root);
}
