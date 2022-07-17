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
	if (first->parent == second->parent)
		return (f->parent);

	while (s->parent)
	{
		f = (binary_tree_t *)first;
		while (f->parent)
		{
			if (f == s->parent)
				return (f);
			f = f->parent;
		}
		s = s->parent;
	}
	f = (binary_tree_t *)first;
	while (f->parent)
	{
		s = (binary_tree_t *)second;
		while (s->parent)
		{
			if (s == f->parent)
				return (s);
			s = s->parent;
		}
		f = f->parent;
	}
	return (NULL);
}
