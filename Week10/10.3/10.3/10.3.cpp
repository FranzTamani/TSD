/*
Name: Franz Tamani
StuID: 102114822
Unit: SWE20004 - Technical Software Development
Summary: The program generates 10 random numbers
		 out of 50 and inserts each number in
		 the linked list in ascending order.
*/
#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

struct numbers
{
	int num;
	struct numbers* next;
};

typedef struct numbers NUMBERS;
typedef NUMBERS* NUMBERSPtr;

float calcAvg(NUMBERSPtr current)
{
	float total = 0;
	int elements = 0;
	while (current != NULL)
	{
		total += current->num;
		current = current->next;
		elements++;
	}
	return total / elements;
}

int main()
{
	int num = 0;

	srand(time(0));


	NUMBERSPtr start = new NUMBERS;
	NUMBERSPtr current = new NUMBERS;
	NUMBERSPtr prev = new NUMBERS;
	for (int i = 0; i < 10; i++)
	{
		num = rand() % 50 + 1;
		
		cout << num << endl;

		NUMBERSPtr newPtr = new NUMBERS;
		newPtr->num = num;
		newPtr->next = NULL;

		if (i == 0)
		{
			start = newPtr;
		}
		else
		{
			//Inserts number in Linked List in sorted order
			current = start;
			prev = NULL;
			while (current != NULL)
			{
				//Number is lower
				if (newPtr->num < current->num)
				{
					//Lowest Number
					if (prev == NULL)
					{
						//New Starting Position
						start = newPtr;
						newPtr->next = current;
						break;
					}
					else
					{
						//Put new value before current value
						prev->next = newPtr;
						newPtr->next = current;
						break;
					}
				}
				else if (newPtr->num == current->num)
				{
					//If number is same as last number
					if (current->next == NULL)
					{
						current->next = newPtr;
					}
					else
					{
						//Put new value in front of current value
						newPtr->next = current->next;
						current->next = newPtr;
					}
					break;
				}
				else if (newPtr->num > current->num)
				{
					//Largest Number
					if (current->next == NULL)
					{
						current->next = newPtr;
						break;
					}
				}
				prev = current;
				current = current->next;
			}
		}
	}

	current = start;
	cout << "Now Printing All List Values" << endl;
	int i = 0;
	while (current != NULL)
	{
		cout << current->num;
		if (current->next != NULL)
			cout << " -> ";
		current = current->next;
		i++;
	}
	cout << endl << i << " Values have been printed" << endl;

	cout << "The Average of all values are: " << calcAvg(start) << endl;
	return 0;
}