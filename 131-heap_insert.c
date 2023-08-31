#include "binary_trees.h"

/**
 * heap_insert - adds a value to the Max Binary Heap.
 * @root: a double pointer to the Heap's root node to place the value
 * @value: the value to store in the node to be inserted
 *
 * Return: the node's pointer after creation
 *         NULL If failed
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new, *flip;
	int size, leaves, sub, bit, level, tmp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	leaves = size;
	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;
	/* subtract all nodes except for bottom-most level */

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;
	/*
	 * Based on the binary, traverse the tree to the first vacant position.
	 * representation of the number of leaves.
	 * Example -
	 * In a fully developed tree with 12 nodes, there are 5 leaves.
	 * the 4th tier of the tree. 5 is 101 in binary. 1 corresponds to
	 * right, 0 to left.
	 * The root node is 101 == RLR, which stands for root->right->left->right.
	 */

	new = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = new) : (tree->left = new);

	flip = new;
	for (; flip->parent && (flip->n > flip->parent->n); flip = flip->parent)
	{
		tmp = flip->n;
		flip->n = flip->parent->n;
		flip->parent->n = tmp;
		new = new->parent;
	}
	/* Flip values with parent until parent value exceeds new value */

	return (new);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: using a tree to get its size
 * Return: the tree's size
 *         if tree is NULL, then 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
