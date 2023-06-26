#include "sort.h"

/**
 * swap_ints - swaps two elements in an array
 * @a: first element
 * @b: second element
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - sort an array of integers in ascending order
 * using selection sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t k, j;

	if (array == NULL || size < 2)
		return;
	for (k = 0; k < size - 1; k++)
	{
		min = array + k;
		for (j = k + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + k) != min)
		{
			swap_ints(array + k, min);
			print_array(array, size);
		}
	}
}
