#include "binary_trees.h"

/**
 * binary_tree_preorder - Prints in preorder a binary tree
 * @tree: Pointer to the root of the tree to print
 * @func: Function to print the node
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
