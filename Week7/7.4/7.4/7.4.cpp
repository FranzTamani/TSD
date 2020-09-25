/*
Name: Franz Tamani
StuID: 102114822
Unit: SWE20004 - Technical Software Development
Summary: Find the popularity of players
		 in different states.
*/
#include<iostream>
#include<iomanip>

using namespace std;

#define SIZE 5

int main()
{
	int arr[SIZE][SIZE], player, i, j;
	bool loop = true;
	char city;
	//Initialize all values to 0
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			arr[i][j] = 0;
		}
	}

	cout << "City  " << setw(20) << "Player" << endl;
	cout << "M - Melbourne" << setw(20) << "1 - Ricky Ponting" << endl;
	cout << "S - Sydney " << setw(20) << "2 - Shane Warne" << endl;
	cout << "B - Brisbane  " << setw(20) << "3 - Donald Bradman" << endl;
	cout << "A - Adelaide " << setw(20) << "4 - Glenn McGarth" << endl;

	cout << "\nFor each entry, enter the city code\nfollowed by the person code."
		<< "\nEnter the letter X to indicate end.\n" << endl;
	do
	{
		cin >> city;
		if (city == 'X') break;
		cin >> player;
		if (player > 4 || player < 1) break;
		switch (city)
		{
		case 'M':
			arr[1][player] += 1;
			break;
		case 'S':
			arr[2][player] += 1;
			break;
		case 'B':
			arr[3][player] += 1;
			break;
		case 'A':
			arr[4][player] += 1;
			break;
		}
	} while (loop);

	cout << "\n------------------------------------------------------------------------------------------" << endl;
	cout << setw(50) << "POPULARITY TABLE" << endl;
	cout << "------------------------------------------------------------------------------------------" << endl;
	cout << "City" << setw(25) << "Ricky Ponting";
	cout << setw(20) << "Shane Warne";
	cout << setw(20) << "Donald Bradman";
	cout << setw(20) << "Glenn McGarth" << endl;
	cout << "------------------------------------------------------------------------------------------" << endl;
	cout << "Melbourne";
	for (i = 1; i <= SIZE - 1; i++)
	{
		cout << setw(20) << arr[1][i];
	}
	cout << "\nSydney   ";
	for (i = 1; i <= SIZE - 1; i++)
	{
		cout << setw(20) << arr[2][i];
	}
	cout << "\nBrisbane ";
	for (i = 1; i <= SIZE - 1; i++)
	{
		cout << setw(20) << arr[3][i];
	}
	cout << "\nAdelaide ";
	for (i = 1; i <= SIZE - 1; i++)
	{
		cout << setw(20) << arr[4][i];
	}
	cout << "\n------------------------------------------------------------------------------------------" << endl;
}