////////////////////////////////////
////Name: Franz Jordaneal Tamani////
////StuID: 102114822		    ////
////////////////////////////////////
#include<iostream>
#include<string>

using namespace std;

int main()
{
	double dec1, dec2;
	int choice;
	bool exitProgram = false;

	do
	{
		cout << "Enter 2 decimal numbers" << endl;
		cin >> dec1 >> dec2;

		cout << "Press 1:Addition, 2:Multiplication, 3:Division" << endl;
		cin >> choice;

		switch (choice)
		{
		default:
			while (choice != 1 && choice != 2 && choice != 3)
			{
				cout << "Enter a Valid Number" << endl;
				cout << "Press 1:Addition, 2:Multiplication, 3:Division" << endl;
				cin >> choice;
			}
		case 1:
			cout << "Result: " << dec1 + dec2 << endl;
			break;
		case 2:
			cout << "Result: " << dec1 * dec2 << endl;
			break;
		case 3:
			cout << "Result: " << dec1 / dec2 << endl;
			break;
		}
		
		//Asks User if they want to continue or exit
		cout << "Press 1:Continue 2:Exit" << endl;
		cin >> choice;

		switch (choice)
		{
		default:
			while (choice != 1 && choice != 2 && choice != 3)
			{
				cout << "Enter a Valid Number" << endl;
				cout << "Press 1:Continue 2:Exit" << endl;
				cin >> choice;
			}
		case 1:
			continue;
		case 2:
			exitProgram = true;
		}
	} while (!exitProgram);
	
}