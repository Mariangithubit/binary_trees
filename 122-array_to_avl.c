#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree out of an array..
 * @array: a pointer to the array's initial element that will be transformed.
 * @size: The num of the @array's element count.
 * Return: a NULL value in the event of failure,
 *	or a pointer to the constructed AVL's root node.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t i, j;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}
		if (j == i)
		{
			if (avl_insert(&tree, array[i]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
