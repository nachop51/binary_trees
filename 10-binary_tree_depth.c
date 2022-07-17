#include "binary_trees.h"

/**
 * binary_tree_depth - Calculates the depth of a binary tree
 * @tree: Pointer to the tree
 *
 * Return: The depth of the binary tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree || !tree->parent)
		return (0);
	return (binary_tree_depth(tree->parent) + 1);
}
