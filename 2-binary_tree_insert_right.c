#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child
 * of another node
 * @parent: pointer to binary_tree_s
 * @value: int
 *
 * Return: binary_tree_t *
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	if(parent == NULL)
		return (NULL);

	binary_tree_t *new_node = binary_tree_node(parent, value);
	if(new_node == NULL)
		return (NULL);

	if(parent->right == NULL)
	{
		parent->right = new_node;
	}
	else
	{
		new_node->right = parent->right;  
		parent->right->parent = new_node;
		parent->right = new_node;
	}
	return (new_node);
}
