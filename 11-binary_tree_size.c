#include "binary_trees.h"


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
