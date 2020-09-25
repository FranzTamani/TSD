/*
Name: Franz Tamani
StuID: 102114822
Unit: SWE20004 - Technical Software Development
Summary: Reorders 3 given numbers in ascending order.
*/
#include <iostream>

using namespace std;

void reorder(int *a, int *b, int *c)
{
	int temp;	//used for ordering numbers
	//Orders numbers from left to right
	if (*a > *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
	if (*b > *c)
	{
		temp = *b;
		*b = *c;
		*c = temp;
	}

	//Orders numbers from right to left.
	if (*c < *b)
	{
		temp = *b;
		*b = *c;
		*c = temp;
	}
	if (*b < *a)
	{
		temp = *b;
		*b = *a;
		*a = temp;
	}
}

int main()
{
	while (!cin.fail())
	{
		int arr[3];	//used to store and print numbers.
		//Asks the user to input data
		cout << "Enter 3 Numbers" << endl;
		for (int i = 0; i < 3; i++)
		{
			cin >> arr[i];
		}

		//Prints numbers in original order
		cout << "\nOriginal Number: ";
		for (int i = 0; i < 3; i++)
		{
			cout << arr[i] << " ";
		}

		//Reorders the numbers
		reorder(&arr[0], &arr[1], &arr[2]);

		//Prints numbers after reordering them
		cout << "\n\nReordered Number: ";
		for (int i = 0; i < 3; i++)
		{
			cout << arr[i] << " ";
		}
	}
	return 0;
}