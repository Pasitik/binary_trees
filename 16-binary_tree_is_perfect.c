#include "binary_trees.h"



/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL or not perfect, 0.
 *         Otherwise, 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = bt_height(tree->left);
	right_height = bt_height(tree->right);

	if (left_height == right_height)
	{
		binary_tree_is_perfect(tree->left);
		binary_tree_is_perfect(tree->right);
		return (((tree->left && tree->right) ||
			(tree->left == NULL && tree->right == NULL)) ? 1 : 0);
	}

	return (0);
}
