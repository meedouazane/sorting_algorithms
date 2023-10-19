#include "sort.h"
/**
 * selection_sort - function that sorts an array using the Selection sort
 * @array: an array of integers
 * @size: size of the array
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	int i, j, z;
	int tmp, min = 0;

	for (i = 0; i < (int)size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < (int)size; j++)
		{
			if (array[min] > array[j])
				min = j;
		}
		if (min != i)
		{
		tmp = array[i];
		array[i] = array[min];
		array[min] = tmp;
		for (z = 0; z < (int)size ; z++)
		{
			if (z == (int)size - 1)
				printf("%d", array[z]);
			else
				printf("%d, ", array[z]);
		}
		printf("\n");
		}
	}
}

