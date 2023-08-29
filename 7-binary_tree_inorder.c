#include "binary_trees.h"

/**
 * binary_tree_inorder - goes through a binary tree
 * using in-order traversal
 * @tree: pointer to binary_tree_t
 * @func: pointer to function
 *
 * Return: int
 */
void binary_tree_inorder(
		const binary_tree_t *tree, void (*func)(int))
{
	if(tree == NULL)
		return;
	if(func == NULL)
		return;
	binary_tree_preorder(tree->left, func);
	func(tree->n);
	binary_tree_preorder(tree->right, func);
}
