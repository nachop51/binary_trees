#include "binary_trees.h"

/**
 * max - Finds the last node
 * @tree: Pointer to the root node of the tree
 * @value: Value to search
 * Return: The max between the two ints
 */
avl_t *max(avl_t *tree, int value)
{
	avl_t *node = tree;
	avl_t *prev = NULL;

	while (node && node->n != value)
	{
		prev = node;
		if (node->n == value)
			return (node);
		if (value > node->n)
			node = node->right;
		else
			node = node->left;
	}
	return (prev);
}

/**
 * height - Calculates the height of a binary tree
 * @tree: Pointer to the tree
 *
 * Return: The height of the binary tree
 */
size_t height(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);
	left = height(tree->left);
	right = height(tree->right);
	return (left > right ? left + 1 : right + 1);
}

/**
 * search_prev - Searches for the previous node in a binary tree
 * @tree: Pointer to the tree
 * @value: Value to search for
 * Return: Pointer to the previous node or NULL if it fails
 */
avl_t *search_prev(avl_t **tree, int value)
{
	avl_t *node = *tree;
	avl_t *prev = NULL;

	while (node)
	{
		prev = node;
		if (node->n == value)
			return (prev);
		if (value > node->n)
			node = node->right;
		else
			node = node->left;
	}
	return (prev ? prev : *tree);
}

/**
 * avl_aux - Auxiliary function to insert a node in an AVL tree
 * @tree: Pointer to the root of the tree
 * @value: Value to insert in the tree
 * @parent: Pointer to the parent of the node to insert
 * Return: Pointer to the new node or NULL if it fails
 */
avl_t *avl_aux(avl_t **tree, int value, avl_t *parent)
{
	int balance;
	avl_t *node = *tree, *aux;

	if (!tree)
		return (NULL);
	if (!*tree)
	{
		*tree = binary_tree_node(parent, value);
		if (!*tree)
			return (NULL);
		return (*tree);
	}
	if (value < (*tree)->n)
		(*tree)->left = avl_aux(&(*tree)->left, value, parent);
	else if (value > (*tree)->n)
		(*tree)->right = avl_aux(&(*tree)->right, value, parent);
	else
		return (*tree);
	balance = height(node->left) - height(node->right);

	if (balance > 1 && value < node->left->n)
		return (binary_tree_rotate_right(node));

	if (balance < -1 && value > node->right->n)
		return (binary_tree_rotate_left(node));

	if (balance > 1 && value > node->left->n)
	{
		node->left = binary_tree_rotate_left(node->left);
		return (binary_tree_rotate_right(node));
	}

	if (balance < -1 && value < node->right->n)
	{
		node->right = binary_tree_rotate_right(node->right);
		return (binary_tree_rotate_left(node));
	}
	aux = max(node, value);
	return (aux);
}

/**
 * avl_insert - Inserts a node in a AVL tree
 * @tree: Pointer to the root of the tree
 * @value: Value to insert in the tree
 * Return: Pointer to the new node or NULL if it fails
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *parent = search_prev(tree, value);

	return (avl_aux(tree, value, parent));
}
