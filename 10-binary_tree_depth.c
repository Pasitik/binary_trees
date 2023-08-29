#include "binary_trees.h"

/**
* binary_tree_depth - measures the depth of a binary tree
* @tree: pointer to binary_tree_t
*
* Return: size_t
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if(tree == NULL)
        return (0);
        
    size_t depth = 0;
    
    if(tree->parent)
        depth = binary_tree_depth(tree->parent) + 1;
    else
        return (0);
        
    return (depth);
}
