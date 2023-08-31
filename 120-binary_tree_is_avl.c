#include "binary_trees.h"


/**
 *binary_tree_is_bst_helper - Rotating the tree to the right
 *@tree: The tree to be evaluated and modified
 *@min: The tree to be evaluated and modified
 *@max: The tree to be evaluated and modified
 *Return: Newly modified tree
 */
int binary_tree_is_bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (binary_tree_is_bst_helper(tree->left, min, tree->n) &&
	    binary_tree_is_bst_helper(tree->right, tree->n, max));
}


/**
 *binary_tree_is_bst - Rotating the tree to the right
 *@tree: The tree to be evaluated and modified
 *Return: Newly modified tree
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_is_bst_helper(tree, INT_MIN, INT_MAX));
}


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
 * avl_height - Builds a Binary Search Tree from an array
 *
 * @tree: Pointer to the first element of the array to be converted
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */
int avl_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (-1);
	return (1 + max_(avl_height(tree->left), avl_height(tree->right)));
}



/**
 * binary_tree_is_avl - Builds a Binary Search Tree from an array
 *
 * @tree: Pointer to the first element of the array to be converted
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	 int balance;

	if (tree == NULL)
		return (1);

	balance = avl_height(tree->left) - avl_height(tree->right);

	if (balance < -1 || balance > 1)
		return (0);

	if (!binary_tree_is_bst(tree))
		return (0);

	return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}

