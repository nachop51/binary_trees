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

bst_t *find_next(bst_t *tree)
{
	bst_t *node = NULL;

	if (tree->right)
	{
		node = tree->right;
		while (node->left)
			node = node->left;
		return (node);
	}
	else if (tree->left)
	{
		node = tree->left;
		while (node->right)
			node = node->right;
		return (node);
	}
	return (NULL);
}

/**
 * bst_remove - Removes a node from a BST
 * @root: Pointer to the root of the tree
 * @value: Value to remove from the tree
 *
 * Return: Pointer to the new root or NULL if it fails
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = NULL, *target = NULL;

	if (!root)
		return (NULL);
	target = bst_search(root, value);
	if (!target)
		return (NULL);
	node = find_next(target);
	if (!node)
		return (NULL);
	if (target->left)
	{
		node->left = target->left;
		node->left->parent = node;
	}
	if (target->right)
	{
		node->right = target->right;
		node->right->parent = node;
	}
	node->parent = target->parent ? target->parent : NULL;
	if (node->parent && target->parent->left == target)
		node->parent->left = node;
	else if (node->parent && target->parent->right == target)
		node->parent->right = node;
	else if (!node->parent)
		root = node;
	free(target);
	return (node);
}
