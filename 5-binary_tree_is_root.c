#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if a node is a root
 * @node: pointer to binary_tree_t
 *
 * Return: int
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if(node == NULL)
		return (0);

	if(node->left != NULL && node->right != NULL)
		return (1);

	return (0);
}
