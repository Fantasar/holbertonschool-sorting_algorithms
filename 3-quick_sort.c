#include "sort.h"

/**
* swap - Swaps two integers in an array
* @a: First integer
* @b: Second integer
*/
void swap(int *a, int *b)
{
	if (*a != *b)
	{
		int tmp = *a;

		*a = *b;
		*b = tmp;
	}
}

/**
* partition - Partitions the array
* @array: The array to be sorted
* @low: Starting index
* @high: Ending index
* @size: Total size of the array
*
* Return: The index of the pivot after partitioning
*/
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	if (i + 1 != high)
		print_array(array, size);
	return (i + 1);
}

/**
* quick_sort_rec - Recursive helper for quick_sort
* @array: The array to be sorted
* @low: Starting index
* @high: Ending index
* @size: Total size of the array
*/
void quick_sort_rec(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = partition(array, low, high, size);

		quick_sort_rec(array, low, pivot_index - 1, size);
		quick_sort_rec(array, pivot_index + 1, high, size);
	}
}

/**
* quick_sort - Sorts an array of integers in ascending order
*               using the Quick sort algorithm.
* @array: The array to be sorted
* @size: The size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}
