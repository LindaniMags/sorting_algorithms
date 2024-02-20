#include "sort.h"

/**
 * swap_el - Swaps two array elements
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
 * shell_sort - Sort integers using the shell sort algorithm.
 * @array: Integer array.
 * @size: Array size.
 */
void shell_sort(int *array, size_t size)
{
	size_t interval, i, j;

	if (array == NULL || size < 2)
		return;

	for (interval = 1; interval < (size / 3);)
		interval = interval * 3 + 1;

	for (; interval >= 1; interval /= 3)
	{
		for (i = interval; i < size; i++)
		{
			j = i;
			while (j >= interval && array[j - interval] > array[j])
			{
				swap_el(array + j, array + (j - interval));
				j -= interval;
			}
		}
		print_array(array, size);
	}
}
