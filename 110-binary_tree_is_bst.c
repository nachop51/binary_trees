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
 * binary_tree_is_bst - Checks if a binary tree is a BST
 * @tree: Pointer to the tree
 *
 * Return: If the tree is BST or not (Binary Search Tree)
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (aux_is_bst(tree, INT_MIN, INT_MAX));
}
