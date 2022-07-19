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
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the tree
 *
 * Return: If its completed or not
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *sibling = NULL;
	if (!tree || (!tree->left && tree->right))
		return (0);
	sibling = binary_tree_sibling((binary_tree_t *)tree);
	if (tree->left && sibling)
	{
		if (tree->left)
			return (NULL);
	}
	return (binary_tree_is_complete(tree->left) && binary_tree_is_complete(tree->right));
}
