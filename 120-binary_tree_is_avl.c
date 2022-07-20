#include "binary_trees.h"
#include <limits.h>

/**
 * aux_is_bst - Auxiliary function to check if a bt is bst
 * @tree: Pointer to the root of the tree
 * @low: Lowest value in the tree
 * @high: Highest value in the tree
 *
 * Return: If the three is BST or not
 */
int aux_is_bst(const binary_tree_t *tree, int low, int high)
{
	if (!tree)
		return (1);
	if (tree->n < low || tree->n > high)
		return (0);
	return (aux_is_bst(tree->left, low, tree->n - 1) &&
			aux_is_bst(tree->right, tree->n + 1, high));
}

/**
 * max - Finds the max between two ints
 * @x: First int
 * @y: Second int
 * Return: The max between the two ints
 */
int max(int x, int y)
{
	return ((x >= y) ? x : y);
}

/**
 * height - Calculates the height of a binary tree
 * @tree: Pointer to the tree
 *
 * Return: The height of the binary tree
 */
size_t height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + max(height(tree->left), height(tree->right)));
}

/**
 * aux_is_balanced - Auxiliary function to check if a bt is balanced
 * @tree: Pointer to the root of the tree
 * Return: If the tree is balanced or not
 */
int aux_is_balanced(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (1);
	left = height(tree->left);
	right = height(tree->right);
	if (abs(left - right) <= 1 &&
		aux_is_balanced(tree->left) && aux_is_balanced(tree->right))
		return (1);
	return (0);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is an AVL tree
 * @tree: Pointer to the tree
 * Return: If the tree is AVL or not
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (aux_is_bst(tree, INT_MIN, INT_MAX))
		return (aux_is_balanced(tree));
	return (0);
}
