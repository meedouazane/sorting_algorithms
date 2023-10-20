#include "sort.h"
/**
 * partition - first part of quick sorting.
 * @array: array of int
 * @low: first element in an array
 * @high: last element in an array
 * Return: the index of element pivot in array
 */
int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int tmp, j = 0;
	size_t size = 0;

	size = sizeof(array) + 2;
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
 * @low: first element in an array
 * @high: last element in an array
 * Return: Nothing
 */
void quick_sort_helper(int *array, int low, int high)
{
	int part = 0;

	if (low < high)
	{
		part = partition(array, low, high);
		quick_sort_helper(array, low, part - 1);
		quick_sort_helper(array, part + 1, high);
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
	int high, low = 0;

	if (!array || !size)
		return;

	high = size - 1;
	quick_sort_helper(array, low, high);
}
