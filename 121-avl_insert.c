#include "binary_trees.h"


/**
 * height - Builds a Binary Search Tree from an array
 *
 * @node: Pointer to the first element of the array to be converted
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */
int height(avl_t *node)
{
	if (node == NULL)
		return (0);

	return (node->height);
}
/**
 * balance - Builds a Binary Search Tree from an array
 *
 * @node: Pointer to the first element of the array to be converted
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */
int balance(avl_t *node)
{
	if (node == NULL)
		return (0);

	return (height(node->left) - height(node->right));
}


/**
 * avl_insert - Builds a Binary Search Tree from an array
 *
 * @tree: Pointer to the first element of the array to be converted
 * @data: data to insert
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int data)
{
	int bal;
	avl_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, data);
		return (*tree);
	}
	if (data < (*tree)->n)
	{
		new_node = avl_insert(&((*tree)->left), data);
		(*tree)->left = new_node;
	}
	else if (data > (*tree)->n)
	{
		new_node = avl_insert(&((*tree)->right), data);
		(*tree)->right = new_node;
	}
	else
		return (NULL);
	(*tree)->height = max_(height((*tree)->left), height((*tree)->right)) + 1;
	bal = balance(*tree);
	if (bal > 1 && data < (*tree)->left->n)
		return (binary_tree_rotate_right(*tree));
	if (bal < -1 && data > (*tree)->right->n)
		return (binary_tree_rotate_left(*tree));
	if (bal > 1 && data > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		return (binary_tree_rotate_right(*tree));
	}
	if (bal < -1 && data < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		return (binary_tree_rotate_left(*tree));
	}
	return (*tree);
}
