#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the number of nodes in a binary tree
 * @tree: Pointer to the tree
 *
 * Return: The amount of nodes in the tree
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (!tree)
		return (0);
	if (tree->left || tree->right)
		nodes = 1;
	return (binary_tree_nodes(tree->left) +
			binary_tree_nodes(tree->right) + nodes);
}
