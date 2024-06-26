#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: Pointer to the first integer to swap.
 * @b: Pointer to the second integer to swap.
 *
 * Description: Swaps the values of two integers using pointers.
 */
void swap_ints(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * shell_sort - Sort an array of integers in ascending order
 *              using the shell sort algorithm.
 * @array: Pointer to the array of integers to sort.
 * @size: Size of the array.
 *
 * Description: Sorts the array in ascending order using the shell sort algorithm
 *              with the Knuth interval sequence. Prints the array after each gap iteration.
 */
void shell_sort(int *array, size_t size)
{
    size_t gap, i, j;

    if (array == NULL || size < 2)
        return;

    for (gap = 1; gap < (size / 3);)
        gap = gap * 3 + 1;

    for (; gap >= 1; gap /= 3)
    {
        for (i = gap; i < size; i++)
        {
            j = i;
            while (j >= gap && array[j - gap] > array[j])
            {
                swap_ints(array + j, array + (j - gap));
                j -= gap;
            }
        }
        print_array(array, size);
    }
}

