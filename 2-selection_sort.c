#include "sort.h"

/**
 * swap_int - Swaps two integers in an array
 * @num1: Pointer to initial num
 * @num2: Pointer to next num
 */
void swap_el(int *num1, int *num2)
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: Array of integers
 * @size: Size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min])
				min = j;
		if (min != i)
		{
			swap_el(array + min, array + i);
			print_array(array, size);
		}
	}
}
