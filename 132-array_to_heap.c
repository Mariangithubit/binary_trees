#include "binary_trees.h"

/**
 * array_to_heap - takes an array and creates a Max Binary Heap tree.
 * @array: a reference to the array's first element that
 *	needs to be transformed
 * @size: the array's size in elements
 * Return: a reference to the binary heap's root node.
 *         NULL if failed
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int i;
	heap_t *root = NULL;

	for (i = 0; i < size; i++)
		heap_insert(&root, array[i]);

	return (root);
}
