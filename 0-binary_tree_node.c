#include "binary_trees.h"
/**
 * bt_height - Measures the height of a binary tree
 *
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t bt_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = bt_height(tree->left);
	right_height = bt_height(tree->right);

	return (
			left_height > right_height ?
			left_height + 1 : right_height + 1
		);
}

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to binary_tree_s
 * @value: int
 *
 * Return: binary_tree_t *
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->height = 1;
	return (new_node);
}
