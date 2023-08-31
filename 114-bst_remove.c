#include "binary_trees.h"

bst_t *bst_min_value_node(bst_t *node);
/**
 * bst_remove - Builds a Binary Search Tree from an array
 *
 * @root: Pointer to the first element of the array to be converted
 * @value: Number of elements in the array
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *newRoot = root;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
	{
		root->left = bst_remove(root->left, value);
	}
	else if (value > root->n)
	{
		root->right = bst_remove(root->right, value);
	}
	else
	{
		if (root->left == NULL)
		{
			newRoot = root->right;
			free(root);
			return (newRoot);
		}
		if (root->right == NULL)
		{
			newRoot = root->left;
			free(root);
			return (newRoot);
		}
		newRoot = bst_min_value_node(root->right);
		root->n = newRoot->n;
		root->right = bst_remove(root->right, newRoot->n);
	}
	return (root);
}

/**
 * bst_min_value_node - Builds a Binary Search Tree from an array
 *
 * @node: Pointer to the first element of the array to be converted
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */
bst_t *bst_min_value_node(bst_t *node)
{
	bst_t *current = node;

	while (current && current->left != NULL)
	{
		current = current->left;
	}

	return (current);
}

