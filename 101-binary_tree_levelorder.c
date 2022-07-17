#include "binary_trees.h"

/**
 * binary_tree_levelorder - Prints in levelorder a binary tree
 * @tree: Pointer to the tree
 * @func: Pointer to the function to print the data
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *array[1024];
	int i = 0, j = 1;

	if (!tree || !func)
		return;
	array[i] = (binary_tree_t *)tree;
	for (i = 0; array[i]; i++)
	{
		func(array[i]->n);
		if (array[i]->left)
			array[j++] = array[i]->left;
		if (array[i]->right)
			array[j++] = array[i]->right;
	}
}
