#include "sort.h"

/**
 * partition_array - partitions array
 * @array: array to partition
 * @first_index: first index of array
 * @last_index: last index of array
 * @size: size of array
 * Return: index of pivot
 */

int partition_array(int *array, int first_index, int last_index, size_t size)
{
	int pivot = array[last_index];
	int i = first_index - 1;
	int j, holder;

	for (j = first_index; j < last_index; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			holder = array[i];
			array[i] = array[j];
			array[j] = holder;
			if (i != j)
				print_array(array, size);
		}
	}
	holder = array[i + 1];
	array[i + 1] = array[last_index];
	array[last_index] = holder;
	if (i + 1 != j)
		print_array(array, size);
	return (i + 1);
}

/**
 * quick_sort_helper - helper function for quick_sort
 * @array: array to sort
 * @first_index: first index of array
 * @last_index: last index of array
 * @size: size of array
 */

void quick_sort_helper(int *array, int first_index,
					   int last_index, size_t size)
{
	int p;

	if (first_index < last_index)
	{
		p = partition_array(array, first_index, last_index, size);
		quick_sort_helper(array, first_index, p - 1, size);
		quick_sort_helper(array, p + 1, last_index, size);
	}
}

/**
 * quick_sort - integer sorting algorithm based on quicksort
 * @array: array to sort
 * @size: size of array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_helper(array, 0, size - 1, size);
}
