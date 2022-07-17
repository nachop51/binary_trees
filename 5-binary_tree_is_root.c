#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a node is a root
 * @node: Pointer to the node
 *
 * Return: If the node is root or not
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	return (node && !node->parent);
}
