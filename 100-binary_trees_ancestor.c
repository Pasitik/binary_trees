#include "binary_trees.h"

/**
 * binary_trees_ancestor - find the lowest common ancestor of 2 nodes
 * @first: first node
 * @second: second node
 * Return: pointer to lowest common ancestor, else NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	int dep1, dep2;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first->n == second->n)
		return ((binary_tree_t *)first);

	dep1 = binary_tree_depth(first);
	dep2 = binary_tree_depth(second);
	if (dep1 > dep2)
	{
		while (dep1 > dep2)
		{
			first = first->parent;
			if (first == NULL)
				return (NULL);
			dep1 = binary_tree_depth(first);
		}
	}
	else if (dep2 > dep1)
	{
		while (dep2 > dep1)
		{
			second = second->parent;
			if (second == NULL)
				return (NULL);
			dep2 = binary_tree_depth(second);
		}
	}

	while (first && second)
	{
		if (first->n == second->n)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}

	return (NULL);
}

/**
 * binary_tree_depth - measure the depth of a node in a binary tree.
 * Depth is measured from root parent node going down.
 * @node: pointer to node to measure depth of
 * Return: depth of tree from given node
 */
size_t binary_tree_depth(const binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (0);

	return (binary_tree_depth(node->parent) + 1);
}

