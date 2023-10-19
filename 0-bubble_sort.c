#include "sort.h"
#include <stddef.h>
/**
 *bubble_sort - function that sorts an array of integers in ascending order.
 * @array: pointer to an array
 * @size: size of array
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, z = 0;
	int tmp = 0;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
			for (z = 0; z < size ; z++)
			{
				if (z == size - 1)
					printf("%d", array[z]);
				else
					printf("%d ,", array[z]);
			}
			printf("\n");
		}
	}

}
