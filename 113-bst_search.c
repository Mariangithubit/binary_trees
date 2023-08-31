#include "binary_trees.h"

/**
 * bst_search - searches a binary search tree for a value.
 * @tree: a pointer to the BST's root node.
 * @value: The value in the BST to look for.
 * Return: If the value not found or the tree is NULL, NULL.
 *         Otherwise, A pointer to the node which containing the value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
