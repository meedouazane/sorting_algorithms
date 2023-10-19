#include "sort.h"
/**
 * bubble_sort - function that sorts an array of integers in ascending order.
 * @array: pointer to an array
 * @size: size of array
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	int i, j, z;
	int tmp = 0;

	for (i = 0; i < (int)size - 1; i++)
	{
		for (j = 0; j < (int)size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
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

}
