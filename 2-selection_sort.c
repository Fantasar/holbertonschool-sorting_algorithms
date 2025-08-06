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
* selection_sort - Check the numbers in araay and class.
* @array: Numbers in array
* @size: Size of an array
*/

void selection_sort(int *array, size_t size)
{
size_t a, b, index_min;

if (array == NULL || size < 2)
	{
	return;
	}
for (a = 0; a < size - 1; a++)
	{
	index_min = a;
	for (b = a + 1; b < size; b++)
		{
		if (array[b] < array[index_min])
			{
			index_min = b;
			}
		}
	if (index_min != a)
		{
		swap(&array[a], &array[index_min]);
		print_array(array, size);
		}
	}
}
