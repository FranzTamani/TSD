/*
Name: Franz Tamani
StuID: 102114822
Unit: SWE20004 - Technical Software Development
Summary: Gets alphabetical input from user and 
		 inserts into an array, which is then sorted.
		 Program also finds the most occurring alphabet.
*/
#include<iostream>

using namespace std;

#define SIZE 20

void sort(char arr[SIZE])
{
	//Sorts the array
	for (int i = SIZE - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	//Outputs sorted array
	cout << "\n\nThe Sorted Array is:\n" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i];
	}
}

//Finds the most frequent number in the array
void frequent(char x[SIZE])
{
	//Sourced from Week 7, sample solution
	int max = 0, i;
	char mode;
	int fre[SIZE];

	for (i = 0; i < SIZE; i++)
	{
		fre[i] = (int)x[i];	//copy the array
	}

	for (i = 0; i < SIZE; i++)
	{
		//Resers counter to 0 each loop
		//assigns character to a character in the array
		char character = fre[i];
		int counter = 0;
		for (int j = 0; j < SIZE; j++)
		{
			//if number is the same as 
			if (character == fre[j])
				counter++;
		}
		//If counter is greater than max, then another number 
		//that occcurs more frequently is found
		if (counter > max)
		{
			mode = character;
			max = counter;
		}
	}

	//All Chars the same
	if (max == 20)
	{
		cout << "\n\nAll the characters are the same" << endl;
	}
	//1 character is most occuring
	else if (max > 1 && max < 20)
	{
		//We add 'a' and cast as character for printing.
		cout << "\n\nThe mode is " << mode << " occuring " << max << " times" << endl;
	}
	//All characters unique
	else
	{
		cout << "\n\nAll Characters are Entered Only One Time" << endl;
	}
}

int main()
{
	char arr[SIZE], input;

	cout << "Enter 20 Alphabets" << endl;
	//Gets and validates user input
	for (int i = 0; i < 20; i++)
	{
		while (!((cin >> input) && ((input >= 'a' && input <= 'z'))))
		{
			cout << input << " is not an alphabet" << endl;
			cin.clear();
			cin.ignore();
		}
		if (find(begin(arr), end(arr), input) != end(arr))
		{
			cout << input << " is a duplicate letter" << endl;
		}
		arr[i] = input;
	}

	//Outputs original array order
	cout << "\n\nThe Original Array is:\n" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i];
	}

	//Sorts and Prints Array
	sort(arr);

	//Prints frequency
	frequent(arr);
}