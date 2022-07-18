#include "binary_trees.h"

/**
 * bst_insert - Inserts a node in a BST
 * @tree: Pointer to the root of the tree
 * @value: Value to insert in the tree
 *
 * Return: Pointer to the new node or NULL if it fails
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node = NULL, *last = NULL, *aux = NULL;

	if (!tree)
		return (NULL);
	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		if (!*tree)
			return (NULL);
		return (*tree);
	}
	node = *tree;
	while (node)
	{
		last = node;
		if (value == node->n)
			return (NULL);
		if (value > node->n)
			node = node->right;
		else
			node = node->left;
	}
	aux = binary_tree_node(last, value);
	if (!last)
		last = aux;
	else if (value < last->n)
		last->left = aux;
	else
		last->right = aux;
	return (aux);
}
