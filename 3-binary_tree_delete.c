#include "binary_trees.h"

/**
* binary_tree_delete - deletes an entire binary tree
* @tree: pointer to binary_tree_s
*/
void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_delete(tree->left);
    binary_tree_delete(tree->right);
    free(tree);
}
