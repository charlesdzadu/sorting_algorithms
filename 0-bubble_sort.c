#include "sort.h"

/**
 * bubble_sort - sorts integers with bubble sort algorithm
 * @array: array to sort
 * @size: size of array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int holder;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 1; j < size - i; j++)
		{
			if (array[j - 1] > array[j])
			{
				holder = array[j - 1];
				array[j - 1] = array[j];
				array[j] = holder;

				print_array(array, size);
			}
		}
	}
}
