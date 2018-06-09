#include "myLib.h"
#include <iostream>
#include <set>

int *create_array(int size)
{
	int *arr = new int[size];
	srand(time(NULL));
	std::set<int> unique_numbers;
	while (unique_numbers.size() != size)
	{
		unique_numbers.insert(rand() % size * 5);
	}

	int iterator = 0;
	for (auto i = unique_numbers.begin(); i != unique_numbers.end(); i++)
	{
		arr[iterator] = *i;
		iterator++;
	}
	return arr;
}

int odinary_search(int arr[], int size, int fn)
{
	for (int i(0); i < size; i++)
	{
		if (arr[i] == fn)
			return i;
	}
	return -1;
}

int min(int x, int y)
{ 
	return (x <= y) ? x : y; 
}

int fib_search(int arr[], int n, int x)
{
	int fibMMm2 = 0;   
	int fibMMm1 = 1;   
	int fibM = fibMMm2 + fibMMm1;  

	while (fibM < n)
	{
		fibMMm2 = fibMMm1;
		fibMMm1 = fibM;
		fibM = fibMMm2 + fibMMm1;
	}

	int offset = -1;
	int i = 0;

	while (fibM > 1 || arr[i] != x)
	{
		i = min(offset + fibMMm2, n - 1);

		if (arr[i] < x)
		{
			fibM = fibMMm1;
			fibMMm1 = fibMMm2;
			fibMMm2 = fibM - fibMMm1;
			offset = i;
		}

		else if (arr[i] > x)
		{
			fibM = fibMMm2;
			fibMMm1 = fibMMm1 - fibMMm2;
			fibMMm2 = fibM - fibMMm1;
		}

		else
			return i;
	}

	if (fibMMm1 && arr[offset + 1] == x)
		return offset + 1;
	return -1;
}

int interpolation_search(int arr[], int size, int key)
{
	int low = 0;
	int high = size - 1;
	int pos = 0;


	while ((high >= low || key > arr[low] || arr[high] > key))
	{
		pos = low + (((double)(high - low) / (arr[high] - arr[low]))*(key - arr[low]));

		if (arr[pos] == key)
			return pos;

		if (arr[pos] < key)
			low = pos + 1;

		else
			high = pos - 1;
	}
}

int hashFn(int arr[], int size, int key)
{
	int *array = new int[size * 5];
	for (int i(0); i < size; i++)
		array[arr[i]] = arr[i];
	if (array[key])
		return key;
	return -1;
}