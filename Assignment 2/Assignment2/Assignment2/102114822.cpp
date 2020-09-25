/*
Name: Franz Tamani
StuID: 102114822
Unit: SWE20004 - Technical Software Development
Summary: Program determines whether a given
		 card number is valie or not.
*/

#include<string>
#include<iostream>

using namespace std;

int find_sum1(int num[], int size)
{
	int result = 0;
	int sum1[10];	//Numbers will be no more than 10
	int j = 0;		//Used as counter
	int num1 = 0;	//Used for number 10+
	int num2 = 0;	//Used for number 10+

	//Size - 2 as last number us ignored
	for (int i = size - 2; i >= 0; i -= 2)
	{
		sum1[j] = num[i];

		num[i] *= 2;
		if (num[i] > 9)
		{
			num1 = num[i] % 10; //Extracts first digit ie 15 = 1 & 5, 5 is extracted.
			num2 = num[i] / 10; //Extracts second digit ie 15 = 1 & 5, 1 is extracted.
			//cout << "Num1 = " << num1 << ", Num2 = " << num2 << endl;
			result += (num1 + num2);
		}
		else
		{
			result += num[i];
		}
		j++;
	}

	//Prints out numbers being used in find_sum1
	cout << "Numbers for sum1 are ";
	for (int i = 0; i < j; i++)
	{
		cout << sum1[i] << " ";
	}
	cout << endl;

	return result;
}

int find_sum2(int num[], int size)
{
	int result = 0;
	int sum1[10]; //numbers will not be longer that 10
	int j = 0;	//Used as a counter

	//Size - 3 as last number us ignored
	//And - 2 already done in find_sum1
	for (int i = size - 3; i >= 0; i -= 2)
	{
		sum1[j] = num[i];
		result += num[i];
		j++;
	}

	//Prints out numbers being used in find_sum2
	cout << "Numbers for sum3 are ";
	for (int i = 0; i < j; i++)
	{
		cout << sum1[i] << " ";
	}
	cout << endl;
	return result;
}

int main()
{
	int card_number[20]; //Used for card number storage
	int input_number;	//Used for user input
	int size;			//Stores Size of Array
	int sum1;			//Stores Sum1
	int sum2;			//Stores Sum2
	int checksum;		//Stores  Checksum
	
	cout << "Enter a Credit Card Number" << endl;

	//Just to stop errors when checking the array values
	//Initialise all with 0
	for (int i = 0; i < 20; i++)
	{
		card_number[i] = 0;
	}
	
	for (int i = 0; i < 20; i++)
	{
		cin >> input_number;
		if (input_number == -1)
			break;
		else
			card_number[i] = input_number;
		size = i + 1;	// Counter for how many numbers there are.
	}

	cout << "\nCredit card number is: ";
	//Prints out credit card numbers
	for (int i = 0; i < size; i++)
	{
		cout << card_number[i];
	}
	cout << endl;

	sum1 = find_sum1(card_number, size); //Gets sum1
	cout << "Sum 1 is " << sum1 << endl;

	sum2 = find_sum2(card_number, size); //Gets sum2
	cout << "Sum 2 is " << sum2 << endl;

	checksum = ((sum1 + sum2) * 9) % 10; //Gets checksum
	cout << "Check sum is " << checksum << endl;
	cout << "Last digit on credit card is " << card_number[size - 1] << endl;

	//Checks if Card Number is Valid or Not
	if (checksum == card_number[size - 1])
		cout << "Check sum " << checksum << " and the last digit "
		<< card_number[size - 1] << " are the same: Valid credit card number" << endl;
	else
		cout << "Check sum " << checksum << " and the last digit "
		<< card_number[size - 1] << " are not the same: Invalid credit card number" << endl;
}