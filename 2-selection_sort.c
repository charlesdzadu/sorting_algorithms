#include "sort.h"

/**
 * selection_sort - integer sorting algorithm based on selection
 * @array: array to sort
 * @size: size of array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int holder;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		if (min != i)
		{
			holder = array[i];
			array[i] = array[min];
			array[min] = holder;
			print_array(array, size);
		}
	}
}
