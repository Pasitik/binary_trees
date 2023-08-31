#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_is_complete_recursive(tree, 0,
			binary_tree_size(tree)));
}

/**
 * binary_tree_is_complete_recursive - Recursive helper
 * function to check completeness
 *
 * @tree: Pointer to the root node of the tree to check
 * @index: Current index in the tree
 * @node_count: Total number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete_recursive(const binary_tree_t *tree,
		size_t index, size_t node_count)
{
	if (tree == NULL)
		return (1);

	if (index >= node_count)
		return (0);

	return (binary_tree_is_complete_recursive(tree->left, 2 * index + 1,
				node_count) &&
	    binary_tree_is_complete_recursive(tree->right, 2 * index + 2,
		    node_count));
}

/**
* binary_tree_size - measures the size of a binary tree
* @tree: pointer to binary_tree_t
*
* Return: size_t
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t l, r = 0;

	if (tree == NULL)
		return (0);

	l = binary_tree_size(tree->left);
	r = binary_tree_size(tree->right);

	return (l + r + 1);
}
