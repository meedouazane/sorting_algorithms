#include "sort.h"
/**
 * partition - first part of quick sorting.
 * @array: array of int
 * @low: first element in an array
 * @high: last element in an array
 * @size: size of array
 * Return: the index of element pivot in array
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int tmp, j = 0;

	for (j = low; j <= high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
	}
	tmp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = tmp;
	print_array(array, size);
	return (i + 1);
}
/**
 * quick_sort_helper - first part of quick sort
 * @array: array of int
 * @size: size of array
 * @low: first element in an array
 * @high: last element in an array
 * Return: Nothing
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int part = 0;

	if (low < high)
	{
		part = partition(array, low, high, size);
		quick_sort_helper(array, low, part - 1, size);
		quick_sort_helper(array, part + 1, high, size);
	}
}
/**
 * quick_sort - function that sorts an array using quick sort.
 * @array: array of int
 * @size: size of array
 * Return: Nothing.
 */
void quick_sort(int *array, size_t size)
{
	int high = 0;

	high = size - 1;
	quick_sort_helper(array, 0, high, size);
}
