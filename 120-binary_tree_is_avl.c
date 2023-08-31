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
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = tree->left ? binary_tree_height(tree->left) + 1 : 0;
	right_height = tree->right ? binary_tree_height(tree->right) + 1 : 0;

	return ((left_height > right_height) ? (left_height) : (right_height));
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: If tree is NULL, return 0, else return balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t r, l = 0;

	if (tree == NULL)
		return (0);

	l = binary_tree_height(tree->left);
	r = binary_tree_height(tree->right);
	if (tree->left)
		l++;
	if (tree->right)
		r++;

	return (l - r);
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
		return (0);

	balance = binary_tree_balance(tree);

	if (binary_tree_is_bst(tree) &&  balance)
		return (1);
	return (0);
}

