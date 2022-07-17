#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Rotates a binary tree to the right
 * @tree: Pointer to the tree
 *
 * Return: Pointer to the new root node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *parent;

	if (!tree || !tree->left)
		return (tree);
	parent = tree->left;
	parent->parent = tree->parent;
	if (parent->right)
		(parent->right)->parent = tree;
	tree->left = parent->right;
	parent->right = tree;
	tree->parent = parent;
	return (parent);
}
