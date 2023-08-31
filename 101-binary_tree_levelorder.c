#include "binary_trees.h"

/**
 * binary_tree_levelorder - go through binary tree using level-order traversal
 * @tree: pointer to root of tree
 * @func: function pointer to use while traversing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height, counter;

	if (tree == NULL || func == NULL)
		return;

	height = bt_height(tree);
	for (counter = 0; counter <= height; counter++)
		levelordering(tree, func, counter);
}

/**
 * levelordering - binary tree level ordering recursive helper function
 * @tree: node of a tree, initially the root
 * @func: function pointer to use at each level
 * @height: height of tree from current node
 */
void levelordering(const binary_tree_t *tree, void (*func)(int), int height)
{
	if (tree == NULL)
		return;
	else if (height == 0)
		func(tree->n);
	else
	{
		levelordering(tree->left, func, height - 1);
		levelordering(tree->right, func, height - 1);
	}
}


