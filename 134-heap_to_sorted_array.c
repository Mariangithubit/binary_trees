#include "binary_trees.h"

/**
 * tree_size - estimates the heights of a binary tree as a whole.
 * @tree: pointer to the tree's root node to determine its height
 * Return: If the tree is NULL, height or 0
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = 1 + tree_size(tree->left);

	if (tree->right)
		height_r = 1 + tree_size(tree->right);

	return (height_l + height_r);
}

/**
 * heap_to_sorted_array - a Binary Max Heap is converted
 *	to a sorted array of integers
 *
 * @heap: pointer to the heap's root node to convert
 * @size: address to store the array's size
 * Return: pointer to an array that is ordered in reverse order
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, *a = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	a = malloc(sizeof(int) * (*size));

	if (!a)
		return (NULL);

	for (i = 0; heap; i++)
		a[i] = heap_extract(&heap);

	return (a);
}
