#include "sort.h"
/**
 * merge_sort_helper - merge_sort helper
 * @array: array that we want to sort.
 * @first: first elements in array
 * @middle: the middle of array
 * @last: last elements in array
 * Return: Nothing
 */
void merge_sort_helper(int *array, int middle, int first, int last)
{
	int first_len = middle - first + 1;
	int last_len =  last - middle;
	int i, j, z = 0;
	int *left, *right, *left_right;

	left_right = (int *)malloc((first_len + last_len) * sizeof(int));
	if (left_right == NULL)
		return;
	left = left_right;
	right = left_right + first_len;
	for (i = 0; i < first_len; i++)
		left[i] = array[first + i];
	for (i = 0; i < last_len; i++)
		right[i] = array[i + middle + 1];

	i = 0;
	z = first;
	while (i < first_len && j < last_len)
	{
		printf("Merging...\n");
		if (left[i] <= right[j])
		{
			array[z] = left[i];
			i++;
		}
		else
		{
			array[z] = right[j];
			j++;
		}
		printf("[left] : ");
		print_array(left, (size_t)i);
		printf("[right] : ");
		print_array(right, (size_t)j);
		printf("[Done] : ");
		print_array(array, (size_t)z);
		z++;
	}
	while (i < first_len)
	{
		array[z] = left[i];
		i++;
		z++;
	}
	while (j < last_len)
	{
		array[z] = right[j];
		j++;
		z++;
	}
	free(left_right);
}
/**
 * merge_sort_recursion - recursion function for merge sort.
 * @array: array that we need to sort
 * @first: first elements in array
 * @last: last elements in array
 * Return: Nothing
 */
void merge_sort_recursion(int *array, int first, int last)
{
	int middle = 0;

	if (first < last)
	{
		middle = (first + last) / 2;
		merge_sort_recursion(array, first, middle);
		merge_sort_recursion(array, middle + 1, last);
		merge_sort_helper(array, middle, first, last);
	}
}
/**
 * merge_sort -  sorts an array using the Merge sort.
 * @array: array that we want to sort.
 * @size: size of the array.
 * return: Nothing.
 */
void merge_sort(int *array, size_t size)
{
	merge_sort_recursion(array, 0, size - 1);
}
