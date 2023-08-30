#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: If tree is NULL, return 0, else return balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t bf, r, l = 0;
	if(tree == NULL)
		return (0);

	l = binary_tree_height(tree->left) ;
	r = binary_tree_height(tree->right);
	if (tree->left)
		l++;
	if (tree->right)
		r++;

	return (l-r);
}
