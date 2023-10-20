#include "sort.h"
/**
 * partition - first part of quick sorting.
 * @a: array of int
 * @low: first element in an array
 * @high: last element in an array
 * Return: the index of element pivot in array
 */
int partition(int a[], int low, int high)
{
	int pivot = a[high];
	int i = low - 1;
	int tmp, j = 0;

	for (j = low; j <= high; j++)
	{
		if (a[j] < pivot)
		{
			i++;
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
	tmp = a[i + 1];
	a[i + 1] = a[high];
	a[high] = tmp;

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
	size_t size = 0;
	int part = 0;

	size = sizeof(array) + 2;
	if (low < high)
	{
		part = partition(array, low, high);
		quick_sort_helper(array, low, part - 1);
		quick_sort_helper(array, part + 1, high);
		print_array(array, size);
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

	high = size - 1;
	quick_sort_helper(array, low, high);
}
