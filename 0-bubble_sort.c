#include "sort.h"
#include <stdbool.h>

/**
* bubble_sort - Sort an array of integers in ascending order
*               using the Bubble sort algorithm.
* @array: The array to sort.
* @size: The number of elements in the array.
*
* Return: void
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	bool swapped;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = false;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				/* Swap elements */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				print_array(array, size);
				swapped = true;
			}
		}
		if (!swapped)
			break; /* Stop if array is already sorted */
	}
}
