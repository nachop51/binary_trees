#include "binary_trees.h"

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *parent;

	if (!tree || !tree->right)
		return (tree);
	parent = tree->right;
	parent->parent = tree->parent;
	if (parent->left)
		(parent->left)->parent = tree;
	tree->right = parent->left;
	parent->left = tree;
	tree->parent = parent;
	return (parent);
}
