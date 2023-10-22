#include "sort.h"
/**
 * heap - get the max-heap property in an array
 * @array: array of int
 * @size: size of array
 * @i: index of current elements in array
 * Return: Nothing
 */
void heap(int *array, size_t size, int i)
{
	int larg = i;
	int tmp = 0;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < (int)size && array[left] > array[larg])
		larg = left;

	if (right < (int)size && array[right] > array[larg])
		larg = right;
	if (larg != i)
	{
		tmp = array[i];
		array[i] = array[larg];
		array[larg] = tmp;
		heap(array, size, larg);
	}
}
/**
 * heap_sort - function that sorts int using the Heap sort.
 * @array: list of int
 * @size: size of the array
 * return: Nothing.
 */
void heap_sort(int *array, size_t size)
{
	int i, tmp = 0;

	for (i = size; i >= 0; i--)
	{
		print_array(array, size);
		heap(array, size, i);
	}

	for (i = size - 1; i > 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		heap(array, i, 0);
		print_array(array, size);
	}
}

