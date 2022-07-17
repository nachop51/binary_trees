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

/**
 * binary_tree_uncle - Checks if a node has an uncle
 * @node: Pointer to the node
 *
 * Return: If the node has an uncle or not
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	return (binary_tree_sibling(node->parent));
}
