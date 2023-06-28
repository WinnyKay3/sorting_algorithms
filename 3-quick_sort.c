#include "sort.h"

/**
 * swap_ints - swaps two elements in an array
 * @a: the first element
 * @b: the second element
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - partition through an array of integers
 * @array: array of integers
 * @size: the size of the array
 * @g: first index of array
 * @h: last index of array
 *
 * Description: all values must be accurate
 * Return: new index position
 */
int lomuto_partition(int *array, size_t size, int g, int h)
{
	int pivot = array[h], i = g, j;

	for (j = g; j <= h - 1; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap_ints(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (pivot != array[i])
	{
		swap_ints(&array[i], &array[h]);
		print_array(array, size);
	}
	return (i);
}

/**
 * lomuto_sort - implement the quick sort algorithm using recursion
 * @array: the array
 * @size: the size of the array
 * @g: first index of the array
 * @h: the last index of the array
 * Return: 0
 */

void lomuto_sort(int *array, size_t size, int g, int h)
{
	int i;

	if (g < h)
	{
		i = lomuto_partition(array, size, g, h);
		lomuto_sort(array, size, g, i - 1);
		lomuto_sort(array, size, i + 1, h);
	}
}

/**
 * quick_sort - sort an array of integers in ascending order
 * @array: the array
 * @size: the size of the array
 * Return: 0
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
