#include "binary_trees.h"

/**
 * binary_tree_inorder - Prints inorder a binary tree
 * @tree: Pointer to the root of the tree to print
 * @func: Function to print the node
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
