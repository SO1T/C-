#include "myLib.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv)
{
	srand(time(NULL));
	int size;
	int fn;
	cout << "Enter count of numbers: ";
	cin >> size;
	int *arr = create_array(size);
	cout << arr[rand() % size] << endl;
	cout << "Enter finding namber: ";
	cin >> fn;
	
	cout << odinary_search(arr, size, fn) << endl;
	cout << interpolation_search(arr, size, fn) << endl;
	cout << fib_search(arr, size, fn) << endl;
	cout << hashFn(arr, size, fn) << endl;

	system("pause");
	return 0;
}