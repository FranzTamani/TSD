/*
Name: Franz Tamani
StuID: 102114822
FileName: Assignment1.cpp
Description: The program encodes and decodes a number between 2-8 digits(inclusive)
				that is entered by the user so that it can be sent securely.
*/

#include<iostream>
#include<string>

using namespace std;

//Converts a character to an integer.
int char_to_int(char c)
{
	return (int)c - '0';
}

//Converts an integer into a character.
char int_to_char(int i)
{
	return (char)i + '0';
}

//Reverses order of the string, used for 2-3 digits, as it switches the first and last digits.
//Also used for reversing the order for 4-8 digits as numbers are read from right to left.
void reverse_order(string& s)
{
	reverse(s.begin(), s.end());
}

//Used for encoding 4-8 digits.
void four_eight_encode(string& s)
{
	int number;
	int j = 1;
	for (int i = s.size() -1; i >= 0; i--)
	{
		number = char_to_int(s[i]);	//Converts character to integer so we can treat it as an integer(add subtract etc.).
		number += j;			//Adds the position of the number (right to left, from 1-8)
		number = number % 10;		//Gets the remainder.
		s[i] = int_to_char(number); //Converts the integer back to a character
		j++;
		//cout << "number = " << number << endl;	//Used to make sure numbers are being correctly encoded.
	}
}

//Used for decoding 4-8 digits.
void four_eight_decode(string& s)
{
	int number;
	int j = 1;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		number = char_to_int(s[i]);	//Converts character to integer so we can treat it as an integer(add subtract etc.).
		number += 10 - j;	//Adds 10 and subtracts the position of the number (right to left, from 1-8)
		number = number % 10;	//Gets the remainder
		s[i] = int_to_char(number);	//Converts the integer back to a character
		j++;
		//cout << "number = " << number << endl;	//Used to make sure numbers are being correctly decoded.
	}
}

//Encodes Numbers
void encode_numbers(int inputNumbers, string& encoded, bool& extraProtection)
{
	bool validInput = false;
	int size;
	string input;

	encoded = to_string(inputNumbers); //Changes input to string so it can be used more easily.

	size = encoded.size();

	cout << "Number Contains " << size << " Digits" << endl;

	//Reverses order for 2-3 digits as the middle digit for numbers with 3 digits will always stay in the same spot.
	if (size == 2 || size == 3)
	{
		reverse_order(encoded);
	}
	else if (size >= 4 && size <= 8)	// Encodes numbers with 4-8 digits
	{
		four_eight_encode(encoded);
		if (size == 8)					
		{
			cout << "\nDo you want to add a second level of encryption?(y/n) ";	//Asks if extra protection us wanted, if so reverses the number order.

			while (!validInput)
			{
				cin.clear();
				cin >> input;

				if (input == "y" || input == "yes")
				{
					extraProtection = true; //Used for decoding
					reverse_order(encoded); //Adds the extra protection by reversing the order of the already encoded number
					validInput = true;
				}
				else if (input == "n" || input == "no")
				{
					//extraProtection false by default so we don't do anything here.
					validInput = true;
				}
				else
				{
					input = "";	//Clears whatever was set to input.
					cout << "Enter 'y'/'n' or 'yes'/'no'" << endl;
				}
			}
		}
	}
}

//Decodes the encoded numbers
void decode_numbers(string& decoded, string encoded, bool extraProtection)
{
	int size;
	decoded = encoded;
	size = decoded.size();
	if (extraProtection)								//Checks if extra protection was added, if so reverses the number order.
	{
		reverse_order(decoded);
	}
	// Reverses order for 2 and 3, same way as they were encoded in the first place.
	if (size == 2 || size == 3)
	{
		reverse_order(decoded);
	}
	else if (size >= 4 || size <= 8)	//Used for decoding numbers with 4-8 digits.
	{
		four_eight_decode(decoded);
	}
}

int main()
{
	int input;	//input used for getting user input.
	string encoded, decoded;	//encoded and decoded used for storing encoded and decoded numbers
	bool extraProtection = false;	//used for encoding and decoding of 8 digit numbers
	bool validInput = false;		//used for checkin invalid input

	//Gets input from user
	//Makes sure that the input is correct.
	while (!validInput)
	{
		cout << "Please Enter a 2 - 8 digit number" << endl;
		cin >> input;

		if (input < 0)
		{
			cout << "Not a valid input, re-enter the number" << endl;
		}
		else if (input > 0)
		{
			encoded = to_string(input);
			if (encoded.size() < 2 || encoded.size() > 8)
			{
				cout << "Not a valid input, re-enter the number" << endl;
				cin.clear();
				input = 0;
			}
			else {
				validInput = true;
			}
		}
		else if (cin.fail())
		{
			cout << "That is not a valid input" << endl;;
			cin.clear();
			cin.ignore(80, '\n');
		}
	}

	//Encodes numbers.
	encode_numbers(input, encoded, extraProtection);
	cout << "\nThe Encoded Number is: " << encoded << endl;

	//Decodes numbers if there are no errors from encoding
	//Sends over decoded number and bool dictating if extra protection was added
	decode_numbers(decoded, encoded, extraProtection);
	cout << "\nThe Decoded Number is: " << decoded << endl;

	return 0;
}