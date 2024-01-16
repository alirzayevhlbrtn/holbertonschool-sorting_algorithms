#include "sort.h"
/**
 * selection_sort - sorts an array of integers in asc order using selection
 * @array: array to be  sorted
 * @size: the size of the array
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, minimum_index;
	int temp;

	for (i = 0; i < size; i++)
	{
		minimum_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minimum_index])
				minimum_index = j;
		}
		if (minimum_index != i)
		{
			temp =  array[i];
			array[i] = array[minimum_index];
			array[minimum_index] = temp;
		}
	}
}
