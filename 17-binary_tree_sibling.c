#include "binary_trees.h"

/**
 * binary_tree_sibling - Checks if a node has a sibling
 * @node: Pointer to the node
 *
 * Return: If the node has a sibling or not
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	if (node == node->parent->right)
		return (node->parent->left);
	return (node->parent->right);
}
