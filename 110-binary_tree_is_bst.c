#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst_helper - verifie a binary tree is a valid binary search tree.
 * @tree: a pointer to the tree's root node for check.
 * @lo: value of the smallest node so far visited.
 * @hi: value of the highest node so far visited.
 * Return: 1 if the tree is a genuine BST; otherwise, 0.
 */
int is_bst_helper(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		return (is_bst_helper(tree->left, lo, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_bst - check a binary tree is a valid binary search tree.
 * @tree: a pointer to the tree's root node for check.
 * Return: tree returns 1 if it's a valid BST and 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
