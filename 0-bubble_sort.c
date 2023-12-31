#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending orders
 * @array: the arrays to be sorted
 * @size: size of the array
 *
 * Description: prints array after each swap
 */

void bubble_sort(int *array, size_t size)
{
	size_t k, i;
	int tmp;
	int swapped;

	if (array == NULL || size < 2)
		return;
	for (k = 0; k < size - 1; k++)
	{
		swapped = 0;

		for (i = 0; i < size - k - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				swapped = 1;
				print_array(array, size);
			}
		}
		if (swapped == 0)
		{
			return;
		}
	}
}
