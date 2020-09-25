/*
Name: Franz Tamani
StuID: 102114822
Unit: SWE20004 - Technical Software Development
Summary: The program determines whether a word input
		 by user is a palindrome or not, by comparing
		 the values a stack, and the string.
*/
#include<iostream>
#include<string>

using namespace std;

struct Pal
{
	char letter;
	struct Pal* next;
};

typedef struct Pal Palindrome;
typedef Palindrome* palPtr;

int main()
{
	palPtr stack1 = NULL;
	palPtr stack2 = NULL;
	string word;
	bool palindrome = true;
	
	cout << "Enter a word, no spaces, no caps." << endl;
	cin >> word;

	//Inserts the word into a stack
	for (unsigned int i = 0; i < word.size(); i++)
	{
		palPtr newPtr = new Palindrome;
		newPtr->letter = word[i];
		//Push
		newPtr->next = stack1;		//Set old top as next
		stack1 = newPtr;			//Set newPtr as top;
	}

	//Compares stack with letters in a string to determine wether word is
	//a palindrome or not.
	for (unsigned int i = 0; i < word.size(); i++)
	{
		//Compares 2 letters, if they are the same move to the next letter.
		if (stack1->letter == word[i])
		{
			//Pop
			stack1 = stack1->next;
		}
		//If any of the letters do not match, it is not a palindrome
		else
		{
			palindrome = false;
			break;
		}
	}

	if (palindrome)
	{
		cout << "The Word is a Palindrome" << endl;
	}
	else
	{
		cout << "The Word is not a Palindrome" << endl;
	}
	return 0;
}