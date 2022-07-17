#include "binary_trees.h"

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
