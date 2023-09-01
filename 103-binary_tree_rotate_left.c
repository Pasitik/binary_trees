#include "binary_trees.h"

/**
 * rmax_ - returns the max of numbers
 * @a: first number
 * @b: second number
 * Return: the max of a and b
 */
int rmax_(int a, int b)
{
	return (a > b ? a : b);
}

/**
 * lavl_height - Performs a left-rotation on a binary tree
 *
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node after rotation
 */
int lavl_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (-1);

	return (1 + rmax_(lavl_height(tree->left), lavl_height(tree->right)));
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
	if (tree->right->left != NULL)
		temp = tree->right->left;
	if (tree->right == NULL)
		return (tree);
	new_root = tree->right;
	tree->right->left = tree;
	tree->parent = tree->right;
	tree->right->parent = NULL;
	tree->right = temp;
	if (temp != NULL)
		temp->parent = tree;

	new_root->height = rmax_(lavl_height(new_root->left),
			lavl_height(new_root->right)) + 1;
	/**
	 * temp->height = max_(avl_height(temp->left),
	 *  avl_height(temp->right)) + 1;
	 */
	tree->height = rmax_(lavl_height(tree->left),
			lavl_height(tree->right)) + 1;

	return (new_root);
}

