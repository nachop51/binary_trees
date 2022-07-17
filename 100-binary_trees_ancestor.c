#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first:  Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: The lowest common ancestor of the two nodes, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	binary_tree_t *f = (binary_tree_t *)first, *s = (binary_tree_t *)second;

	if (!first || !second)
		return (NULL);
	if (f == s)
		return (f);

	while (f)
	{
		s = second;
		while (s)
		{
			if (f == s->parent || s->parent == f->parent)
				return (s->parent);
			if (f->parent == s)
				return (f->parent);
		}
		f = f->parent;
	}
	return (NULL);
}
