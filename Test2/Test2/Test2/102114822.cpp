#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


struct student 
{
	string name;
	int no_of_units; //Max Number of Units is 5
	string units[5];
	int mark[5];
};

int readFile(fstream&, student[]);
void menu();
void display(student[], int);
double find_average(student[], int, string);
double find_unit_average(student*, int, string);

int main()
{
	student stuArray[100];
	fstream inFile;
	string name;
	double avg;
	int arrSize = 0;
	int menuOption = 0;
	
	arrSize = readFile(inFile, stuArray);

	while (menuOption != -1)
	{
		switch (menuOption)
		{
		case 0:
			menu();
			cin >> menuOption;
			cin.ignore();
			break;
		case 1:
			display(stuArray, arrSize);
			menuOption = 0; // return to menu
			break;
		case 2:
			cout << "Enter a student name: ";
			cin >> name;
			cin.ignore();
			avg = find_average(stuArray, arrSize, name);
			if (avg < 0)
				cout << "No such student in the gradebook" << endl << endl;
			else
			{
				cout << "The average marks of " << name << " is "
					<< fixed << setprecision(2) << avg << endl << endl;
			}
			menuOption = 0; // return to menu
			break;
		//Finds Unit Average
		case 3:
			cout << "Enter unit name: ";
			cin >> name;
			cin.ignore();
			avg = find_unit_average(stuArray, arrSize, name);
			if (avg < 0)
				cout << "No such unit in the database" << endl << endl;
			else
			{
				cout << "The average for " << name << " is "
					<< fixed << setprecision(2) << avg << endl << endl;
			}
			menuOption = 0; // return to menu
			break;
		default:
			break;
		}
	}

	
	return 0;
}

void menu()
{
	cout << "Enter Your Choice" << endl;
	cout << "Enter 1 to display the grade details" << endl;
	cout << "Enter 2 to find the average mark of student" << endl;
	cout << "Enter 3 to find average marks for a particular unit in the gradebook" << endl;
	cout << "Enter -1 to exit the program" << endl;
}

int readFile(fstream& inFile, student stuArr[])
{
	int size = 0;

	inFile.open("marks.txt");

	if (inFile.fail())
	{
		cout << "Input File - ERROR!!!" << endl;
		exit(1);	//1 - define input file error
	}

	for (int i = 0; !inFile.eof(); i++, size++)
	{
		inFile >> stuArr[i].name >> stuArr[i].no_of_units;
		for (int j = 0; j < stuArr[i].no_of_units; j++)
		{
			inFile >> stuArr[i].units[j] >> stuArr[i].mark[j];
		}
	}

	//for (size = 0; !inFile.eof(); size++, stuArr++)
	//{
	//	inFile >> stuArr->name >> stuArr->no_of_units;
	//	for (int i = 0; i < stuArr->no_of_units; i++)
	//	{
	//		inFile >> stuArr->units[i] >> stuArr->mark[i];
	//	}
	//}

	return size;
}

void display(student stuArr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Name: " << stuArr[i].name << endl;
		cout << stuArr[i].name << " has done " << stuArr[i].no_of_units
			<< " units, their marks are" << endl;
		for (int j = 0; j < stuArr[i].no_of_units; j++)
		{
			cout << stuArr[i].units[j] << " " << stuArr[i].mark[j] << endl;
		}
	}
	cout << endl;
}

double find_average(student stuArr[], int size, string name)
{
	double result = 0;
	for (int i = 0; i < size; i++)
	{
		if (stuArr[i].name == name)
		{
			for (int j = 0; j < stuArr[i].no_of_units; j++)
			{
				result += stuArr[i].mark[j];
			}
			result = result / stuArr[i].no_of_units;
			return result;
		}
	}
	return -1;
}

double find_unit_average(student* stuArr, int size, string name)
{
	double avg = 0;
	int unitAmt = 0;
	for (int i = 0; i < size; i++, stuArr++)
	{
		for (int j = 0; j < stuArr->no_of_units; j++)
		{
			if (stuArr->units[j] == name)
			{
				avg += stuArr->mark[j];
				unitAmt++;
			}
		}
	}
	if (unitAmt > 0)
		return avg / unitAmt;
	else
		return -1;
}