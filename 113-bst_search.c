#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a BST
 * @tree: Pointer to the root of the tree
 * @value: Value to search for
 *
 * Return: Pointer to the node or NULL if it fails
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	if (tree->n == value)
		return ((bst_t *)tree);
	if (value < tree->n)
		return (bst_search(tree->left, value));
	return (bst_search(tree->right, value));
}
