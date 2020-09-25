#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

char menu()
{
	bool valid_input = false;
	char choice;
	cout << "Is it a rectangle or square?" << endl;
	cout << "Type R for rectangle" << endl;
	cout << "Type S for Square" << endl;
	cout << "Type E to exit" << endl;
	cin >> choice;
	while (!valid_input)
	{
		switch (choice)
		{
		default:
			cout << "Invalid choice, please try again" << endl;
			cin >> choice;
			break;
		case 'R':
		case 'r':
			valid_input = true;
			return 2;
			break;
		case 'S':
		case 's':
			valid_input = true;
			return 3;
			break;
		case 'E':
		case 'e':
			valid_input = true;
			return 4;
			break;
		}
	}
}

//Generates random bool between min and max
double random_value_generator(double min, double max)
{
	srand(time(0));
	return ((double)rand() / (double)RAND_MAX) * (max - min) + min;
}

double rectangle_area(double length, double breadth)
{
	return length * breadth;
}

double rect_circumference(double length, double breadth)
{
	return 2 * (length + breadth);
}

double square_area(double length)
{
	return length * length;
}

double square_circumference(double length)
{
	return 4 * length;
}

int main()
{
	int menu_input = 1; //1 = default, 2 = Rectangle, 3 = Square, 4 = Exit
	string cm_or_m, unit;
	char choice;
	bool valid_input = false;
	double length, breadth;

	while (menu_input != 4)
	{
		switch (menu_input)
		{
		default:
			menu_input = menu();
			if (menu_input == 4)
				break;
			//Asks the Unit
			valid_input = false;
			while (!valid_input)
			{
				cout << "Is your unit cm or m ?" << endl;
				cin >> cm_or_m;

				if (cm_or_m == "cm" || cm_or_m == "CM")
				{
					unit = "cm";
					valid_input = true;
				}
				else if (cm_or_m == "m" || cm_or_m == "M")
				{
					unit = "m";
					valid_input = true;
				}
				else
				{
					cout << "Wrong unit, give either cm or m" << endl;
				}
			}
		case 2:
			length = random_value_generator(5, 15);
			breadth = random_value_generator(5, 15);
			cout << "The lenght and breadth given by random generator are: " << length << unit
				<< " and " << breadth << unit << endl;
			cout << "Do you want to calculate the are or circumference of the rectangle?" << endl;
			cout << "Enter A for area and C for circumference" << endl;
			cin >> choice;
			valid_input = false;
			while (!valid_input)
			{
				switch (choice)
				{
				default:
					cout << "Wrong choice, re-enter the choice" << endl;
					cin >> choice;
					break;
				case 'A':
				case 'a':
					cout << "The area of the rectangle is " << setprecision(4) << rectangle_area(length, breadth) << unit << "^2\n" << endl;
					menu_input = 0;
					valid_input = true;
					break;
				case 'C':
				case 'c':
					cout << "The circumference of the rectangle is " << setprecision(4) << rect_circumference(length, breadth) << unit << "\n" << endl;
					menu_input = 0;
					valid_input = true;
					break;
				}
			}
			break;
		case 3:
			length = random_value_generator(5, 15);
			cout << "The lenght given by random generator is: " << length << unit << endl;
			cout << "Do you want to calculate the are or circumference of the rectangle?" << endl;
			cout << "Enter A for area and C for circumference" << endl;
			cin >> choice;
			valid_input = false;
			while (!valid_input)
			{
				switch (choice)
				{
				default:
					cout << "Wrong choice, re-enter the choice" << endl;
					cin >> choice;
					break;
				case 'A':
				case 'a':
					cout << "The area of the square is " << setprecision(4) << square_area(length) << unit << "^2\n" << endl;
					menu_input = 0;
					valid_input = true;
					break;
				case 'C':
				case 'c':
					cout << "The circumference of the square is " << setprecision(4) << square_circumference(length) << unit << "\n" << endl;
					menu_input = 0;
					valid_input = true;
					break;
				}
			}
			break;
		case 4:
			break;
		}
	}
}