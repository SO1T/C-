#pragma once
#include <ctime>
#include <cstdlib>

int *create_array(int size);
int odinary_search(int arr[], int size, int fn);
int fib_search(int arr[], int size, int fn);
int interpolation_search(int arr[], int size, int key);
int hashFn(int arr[], int size, int key);