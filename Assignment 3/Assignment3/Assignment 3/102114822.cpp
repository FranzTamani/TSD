/*
Name: Franz Tamani
StuID: 102114822
Unit: SWE20004 - Technical Software Development
Summary: Reads an employee details from file
		 and stores them into memory. 
		 The user can then sort and search
		 the information. The user can also
		 add new information which the program
		 adds into the text file, then reloads it.
*/

#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;

struct employee {
	string name;
	int id;
	float salary;
};

int readFile(employee *emp, ifstream * inFile)
{
	inFile->open("pay.txt");

	if (inFile->fail())
	{
		cout << "Input File - ERROR!!!" << endl;
		exit(1);	//1 - define input file error
	}

	int i = 0;
	while (!inFile->eof())
	{
		string fName;
		string lName;
		*inFile >> fName >> lName >> emp[i].id >> emp[i].salary;
		emp[i].name = fName + " " + lName;
		i++;
	}
	//Closes file
	inFile->close();
	//Subtract i because we added to it above, even though end of file was reached.
	return --i;
}

int menu()
{
	int input = 0;
	cout << "Please Choose a Number" << endl;
	cout << "1. Display Employees' Details" << endl;
	cout << "2. Calculate Average for All Employees' Salaries" << endl;
	cout << "3. Sort Employees Details" << endl;
	cout << "4. Search for a Particular Employees Salary" << endl;
	cout << "5. Find Maximum Salary" << endl;
	cout << "6. Add New Employee to Record" << endl;
	cout << "7. Quit Program" << endl;

	cin >> input;

	return input;
}

void displayEmployees(employee emp[], int size)
{
	cout << "----------------------------------------------------------------------------------------------------" << endl;
	cout << setw(50) << "Employees" << endl;
	cout << "----------------------------------------------------------------------------------------------------" << endl;
	cout << "ID\t" << setw(30) << "Employee Name" << setw(40) << "Salary" << endl;
	cout << "----------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << emp[i].id << "\t" << setw(30);
		cout << emp[i].name << setw(40);
		cout << fixed << setprecision(2) << emp[i].salary << endl;
	}
	cout << "----------------------------------------------------------------------------------------------------" << endl;
}

float calculateAverage(employee emp[], int size)
{
	float total = 0;
	for (int i = 0; i < size; i++)
	{
		total += emp[i].salary;
	}
	//cout << "The total is: " << total << endl;
	return total / size;		//Calculates and Returns Average
}

void sortByName(employee emp[], int size)
{
	for (int i = size - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			//Checks first letters
			if (emp[j].name > emp[j + 1].name)
			{
				swap(emp[j], emp[j + 1]);
			}
		}
	}
}

void sortBySalary(employee emp[], int size)
{
	for (int i = size - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (emp[j].salary > emp[j + 1].salary)
			{
				swap(emp[j], emp[j + 1]);
			}
		}
	}
}

int binarySearch(employee emp[], int start, int last, string name)
{
	//Algorithm sourced from https://www.geeksforgeeks.org/binary-search/
	if (last >= start) {
		int mid = last + (start - last) / 2;

		// If the element is present at the middle 
		// itself 
		if (emp[mid].name == name)
			return mid;

		// If element is smaller than mid, then 
		// it can only be present in left subarray 
		if (emp[mid].name > name)
			return binarySearch(emp, start, mid - 1, name);

		// Else the element can only be present 
		// in right subarray 
		return binarySearch(emp, mid + 1, last, name);
	}

	// Element is not present in the array
	return -1;
}

int findEmployeeSalary(employee emp[], int size, string name)
{
	int input;
	bool leave = false;
	int start = 0, mid = size / 2, end = size;
	while (!leave)
	{
		cout << "Would you like to do: 1. Linear Search 2. Binary Search 0. Cancel" << endl;
		cin >> input;
		switch (input)
		{
		default:
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "That is not a valid entry, try again" << endl;
			break;
		case 1:
			for (int i = 0; i < size; i++)
			{
				if (emp[i].name == name)
					return i;
			}
			return -1;
			break;
		case 2:
			//Need to sort as Binary Search only works on sorted array
			sortByName(emp, size);
			return binarySearch(emp, start, size, name);
			break;
		case 0:
			return -2;
			break;
		}
	}
}

float findMaximum(employee emp[], int size)
{
	//Sorts the Salary and gets the last value as
	//Array is sorted lowest to highest.
	sortBySalary(emp, size);

	return emp[size - 1].salary;
}

//Cannot pass ofstream for some reason
//Says it is a deleted function on tool tip
void updateFile(ofstream * outFile)
{
	string name;
	int id;
	float salary;

	outFile->open("pay.txt", std::ios::app);

	if (outFile->fail())
	{
		cout << "Output File - ERROR!!!" << endl;
		exit(2);	//2 - define input file error
	}

	cout << "Enter Employee Name: " << endl;
	cin.clear();
	cin.ignore();
	getline(cin, name);
	cout << "Enter Employee ID: " << endl;
	cin >> id;
	cout << "Enter Salary: " << endl;
	cin >> salary;
	*outFile << endl << name << " " << id << " " << salary << endl;
	outFile->close();
}

int main()
{
	employee employeeArray[100];
	ifstream inFile;
	ofstream outFile;
	int arraySize, index;
	float average, largestSalary;
	string empName;
	bool leave = false;

	cout << "Welcome, This Application is Used to Manage Employee Details" << endl;

	arraySize = readFile(employeeArray, &inFile);

	while (!leave)
	{
		int menuOption = 0;
		menuOption = menu();
		switch (menuOption)
		{
		case 1:
			//Prints Employees on console
			displayEmployees(employeeArray, arraySize);
			break;
		case 2:
			//Find Average Salary
			average = calculateAverage(employeeArray, arraySize);
			cout << "The Average Salary is: " << fixed << setprecision(2) << average << endl;
			break;
		case 3:
			//Sort Employees
			cout << "Sort Employees By: 1. Name, 2. Salary" << endl;
			cin >> menuOption;
			switch (menuOption)
			{
			case 1:
				sortByName(employeeArray, arraySize);
				cout << "List Has Been Sorted A-Z" << endl;
				break;
			case 2:
				sortBySalary(employeeArray, arraySize);
				cout << "List Has Been Sorted Low-High" << endl;
				break;
			default:
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "That is not a valid entry, try again" << endl;
				break;
			}
			break;
		case 4:
			cout << "Enter Employee Name:" << endl;
			//Ignores new lines entered from old input (enter key)
			cin.clear();
			cin.ignore();
			getline(cin, empName);
			index = findEmployeeSalary(employeeArray, arraySize, empName);
			if (index >= 0)
			{
				cout << "Employee Name: " << employeeArray[index].name << endl;
				cout << "Employee ID: " << employeeArray[index].id << endl;
				cout << "Salary: $" << employeeArray[index].salary << endl;
			}
			else if (index == -1)
			{
				cout << "Cannot Find Employee" << endl;
			}
			menuOption = 0;
			break;
		case 5:
			//Finds Largest Salary
			largestSalary = findMaximum(employeeArray, arraySize);
			cout << "The Largest Salary is: $" << largestSalary << endl;
			break;
		case 6:
			//Enter New Employee
			updateFile(&outFile);
			arraySize = readFile(employeeArray, &inFile);
			break;
		case 7:
			return 0;
			break;
		default:
			//Clears failed cin.
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "That is not a valid entry, try again" << endl;
			break;
		}
	}
}