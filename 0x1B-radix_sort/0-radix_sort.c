#include "sort.h"

/**
 * current_digit_sort - sort
 * @array: array
 * @size: size
 * @tmp: temp
 * @exp: exp digit
 * Return: array sort
 */
int current_digit_sort(int *array, size_t size, int *tmp, long exp)
{
	size_t i;
	int mynum[10] = {0};

	for (i = 0; i < size; i++)
		mynum[(array[i] / exp) % 10]++, tmp[i] = 0;
	for (i = 1; i < 10; i++)
		mynum[i] += mynum[i - 1];
	for (i = size - 1; i >= 0; i--)
		tmp[--mynum[(array[i] / exp) % 10]] = array[i];
	for (i = 0; i < size; i++)
		array[i] = tmp[i];
	return (0);
}
/**
 * radix_sort - sort
 * @array: array
 * @size: size
 * Return: nothing
 */
void radix_sort(int *array, size_t size)
{
	size_t i;
	long exp = 1;
	int *tmp, max = INT_MIN;

	if (!array || size < 2)
		return;

	tmp = malloc(sizeof(int *) * size);
	if (!tmp)
		return;

	for (i = 0; i < size; i++)
		max = array[i] > max ? array[i] : max;

	while (max / exp > 0)
	{
		current_digit_sort(array, size, tmp, exp);
		print_array(array, size);
		exp *= 10;
	}
	free(tmp);
}
