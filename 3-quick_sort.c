#include "sort.h"

void swap_el(int *num1, int *num2);
void lomuto_sort(int *array, size_t size, int left, int right);
int partition(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * partition - Swaps elements less than pivot
 * @array: Array of integers.
 * @size: Array size.
 * @left: Index start.
 * @right: Index end.
 *
 * Return: Partition index.
 */
int partition(int *array, size_t size, int left, int right)
{
	int *pivot, upper_, lower_;

	pivot = array + right;
	for (upper_ = lower_ = left; lower_ < right; lower_++)
	{
		if (array[lower_] < *pivot)
		{
			if (upper_ < lower_)
			{
				swap_el(array + lower_, array + upper_);
				print_array(array, size);
			}
			upper_++;
		}
	}

	if (array[upper_] > *pivot)
	{
		swap_el(array + upper_, pivot);
		print_array(array, size);
	}

	return (upper_);
}

/**
 * lomuto_sort - Sorts via recursion.
 * @array: Array of integers.
 * @size: Array size.
 * @left: Index start.
 * @right: Index end.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int pos;

	if (right - left > 0)
	{
		pos = partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *order using the quicksort algorithm.
 * @array: Array of integers.
 * @size: Array size.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
