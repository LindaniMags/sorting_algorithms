#include <stdio.h>
#include "sort.h"

/**
 * print_array - Prints an array
 * @array: Array of integers
 * @size: Size of array
 */
void print_array(int *array, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

/**
 * bubble_sort -  Sorts an array of integers in ascending order
 * @array: Array of integers
 * @size: Size of array
 */
void bubble_sort(int *array, size_t size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
