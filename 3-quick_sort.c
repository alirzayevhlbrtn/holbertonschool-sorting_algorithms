#include "sort.h"
void quick_sort(int *array, size_t size);
void quick_sort_rec(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);
/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * with the Lomuto partition scheme.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}

/**
 * quick_sort_rec - Recursive helper function for QuickSort
 * @array: Array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 */
void quick_sort_rec(int *array, int low, int high, size_t size)
{
	int partition = 0;

	if (low < high)
	{
		partition = lomuto_partition(array, low, high, size);
		quick_sort_rec(array, low, partition - 1, size);
		quick_sort_rec(array, partition + 1, high, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for QuickSort
 * @array: Array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 * Return: Index of the pivot element
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int i = 0, j = 0, pivot = 0, aux = 0;

	pivot = array[high];
	i = low;

	for (j = low; j < high; ++j)
	{
		if (array[j] < pivot)
		{
			aux = array[i];
			array[i] = array[j];
			array[j] = aux;

			if (aux != array[i])
				print_array(array, size);

			++i;
		}
	}

	aux = array[i];
	array[i] = array[high];
	array[high] = aux;

	if (aux != array[i])
		print_array(array, size);

	return (i);
}
