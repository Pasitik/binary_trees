#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a
 *                       node in a binary tree.
 * @node: A pointer to the node to find the sibling of.
 *
 * Return: If node is NULL or there is no sibling - NULL.
 *         Otherwise - a pointer to the sibling.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent = NULL;
    
    if (node == NULL)
        return (0);
    
    if (node->parent == NULL)
        return (0);
        
    if (node->parent->right == node)
        return node->parent->left;
    return (node->parent->right);
}
