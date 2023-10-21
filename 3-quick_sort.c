#include "sort.h"
/**
 * swapElements - swap two variables without using a temporary variable.
 * @array: array of int
 * @i: pointers to integer.
 * @j: pointers to integer.
 * @size: size of the array.
 * Return: Nothing.
 */
void swapElements(int *array, int *j, int *i, size_t size)
{
	if (*j != *i)
	{
		*j = *j + *i;
		*i = *j - *i;
		*j = *j - *i;
		print_array(array, size);
	}
}
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
	int i, j;

	for (i = j = low; j < high; j++)
	{
		if (array[j] < pivot)
			swapElements(array, &array[j], &array[i++], size);
	}
	swapElements(array, &array[i], &array[high], size);
	return (i);
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
