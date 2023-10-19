#include "sort.h"
/**
 * selection_sort - function that sorts an array using the Selection sort
 * @array: an array of integers
 * @size: size of the array
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, z = 0;
	size_t tmp, min = 0;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min] > array[j])
				min = j;
		}
		if (min != i)
		{
		tmp = array[i];
		array[i] = array[min];
		array[min] = tmp;
		for (z = 0; z < size ; z++)
		{
			if (z == size - 1)
				printf("%d", array[z]);
			else
				printf("%d, ", array[z]);
		}
		printf("\n");
		}
	}
}

