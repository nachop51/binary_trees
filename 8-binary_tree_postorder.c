#include "binary_trees.h"

/**
 * binary_tree_postorder - Prints in postorder a binary tree
 * @tree: Pointer to the root of the tree to print
 * @func: Function to print the node
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
