/*
Name: Franz Tamani
StuID: 102114822
Unit: SWE20004 - Technical Software Development
Summary: Program generates a random number
		 Users guesses what the input is and
		 is given hints to help.
*/


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void guessgame(void);
bool isCorrect(int, int);
void display(int);

int main()
{
	srand(time(0));
	guessgame();
	return 0;
}

void guessgame()
{
	int answer, guess, total;
	char response;
	
	total = 1;
	do
	{
		answer = 1 + rand() % 1000;
		cout << "I have a number between 1 to 1000" << endl;
		cout << "Can you guess my number? (Do you feel lucky?)" << endl;
		cout << "Please enter your first guess: ";
		cin >> guess;
		while (!isCorrect(guess, answer))
		{
			cout << " Try again: ";
			cin >> guess;
			total++;
		}
		cout << "\nExcelent! You guessed the number!" << endl;
		display(total);
		cout << "\nDo you want to play again?" << endl;
		cout << "Please Enter (y/n)? ";
		cin >> response;
	} while (response == 'y');
}

bool isCorrect(int g, int a)
{
	if (g == a)
	{
		return true;
	}
	else if (g > a)
	{
		cout << "\nToo High.";
	}
	else if (g < a)
	{
		cout << "\nToo Low.";
	}
	return false;
}

void display(int t)
{
	cout << "You tried a total of " << t << " times" << endl;
	if (t < 5)
	{
		cout << "Either you're cheating or just lucky" << endl;
	}
	else if (t == 10)
	{
		cout << "Better luck next time lol" << endl;
	}
	else
	{
		cout << "You should be able to do better!" << endl;
	}
}