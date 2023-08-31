#include "binary_trees.h"

/**
 * max_ - returns the max of numbers
 * @a: first number
 * @b: second number
 * Return: the max of a and b
 */
int max_(int a, int b)
{
	return (a > b ? a : b);
}

/**
 * avl_height - Performs a left-rotation on a binary tree
 *
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node after rotation
 */
int avl_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (-1);

	return (1 + max_(avl_height(tree->left), avl_height(tree->right)));
}

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 *
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node after rotation
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp, *new_root;

	temp = NULL;
	if (tree == NULL)
		return (NULL);
	if (tree->left == NULL)
		return (tree);
	if (tree->left->right != NULL)
		temp = tree->left->right;

	new_root = tree->left;
	tree->left->right = tree;
	tree->parent = tree->left;
	tree->left->parent = NULL;
	tree->left = temp;
	if (temp != NULL)
		temp->parent = tree;

	new_root->height = max_(avl_height(new_root->left),
			avl_height(new_root->right)) + 1;
	/**
	 * temp->height = max_(avl_height(temp->left),
	 *  avl_height(temp->right)) + 1;
	 */
	tree->height = max_(avl_height(tree->left),
			avl_height(tree->right)) + 1;

	return (new_root);
}

