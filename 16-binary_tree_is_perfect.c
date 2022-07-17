#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a tree is full
 * @tree: Pointer to the tree
 *
 * Return: If the tree is full or not
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
	return (0);
}

/**
 * binary_tree_height - Calculates the height of a binary tree
 * @tree: Pointer to the tree
 *
 * Return: The height of the binary tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0;
	size_t right = 0;

	if (!tree)
		return (0);
	if (tree->left)
		left = binary_tree_height(tree->left) + 1;
	if (tree->right)
		right = binary_tree_height(tree->right) + 1;
	return (left > right ? left : right);
}

/**
 * binary_tree_is_perfect - Checks if a tree is perfect
 * @tree: Pointer to the tree
 *
 * Return: If the tree is perfect or not
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree || !binary_tree_is_full(tree))
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (binary_tree_height(tree->left) == binary_tree_height(tree->right))
		return (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right));
	return (0);
}
