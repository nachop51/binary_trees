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

/**
 * find_next - Helps to find the next successor of a node
 * @tree: Pointer to the root of the tree
 *
 * Return: Pointer to the next successor of the node or NULL if it fails
 */
bst_t *find_next(bst_t *tree)
{
	tree = tree->right;
	while (tree->left)
		tree = tree->left;
	return (tree);
}

/**
 * helper - Aux function to change two nodes
 * @tree: Pointer to the root of the tree
 * @target: Pointer to the node to be removed
 *
 * Return: Pointer to the new root of the tree or NULL if it fails
 */
void helper(bst_t **tree, bst_t *target)
{
	bst_t *node = NULL;

	node = find_next(target);
	if (node->parent)
		node->parent->left = node->right;
	if (node->right)
		node->right->parent = node->parent;
	node->left = target->left;
	node->left->parent = node;
	node->right = target->right;
	node->right->parent = node;
	node->parent = target->parent ? target->parent : NULL;
	if (target == *tree)
		*tree = node;
	else if (target->parent)
	{
		if (target->parent && target == target->parent->left)
			target->parent->left = node;
		else
			target->parent->right = node;
	}
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
	bst_t *target = NULL, *aux;

	if (!root)
		return (NULL);
	target = bst_search(root, value);
	if (!target)
		return (root);
	if (target->left && target->right)
		helper(&root, target);
	else if ((target->left || target->right) && target->parent)
	{
		aux = target->left ? target->left : target->right;
		aux->parent = target->parent;
		if (target == target->parent->right)
			target->parent->right = aux;
		else
			target->parent->left = aux;
	}
	else if ((target->left || target->right) && !target->parent)
	{
		target->left->parent = NULL;
		root = target->left;
	}
	free(target);
	return (root);
}
