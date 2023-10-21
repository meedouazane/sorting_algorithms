#include "sort.h"
/**
 * shell_sort -  sorts an array using the Shell sort.
 * @array: array of int
 * @size: size of the array
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	int gap, j, i = 0;
	int tmp = 0;

	for (gap = size / 2; gap > 0; gap /= 2)
	{
		for (i = gap; i < (int)size; i += 1)
		{
			tmp = array[i];
			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
				array[j] = array[j - gap];
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
