/*
Name: Franz Tamani
StuID: 102114822
Unit: SWE20004 - Technical Software Development
Summary: The program gets employee info from user.
		 User can then get employee and company	
		 details using their names.
*/


#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

#define SIZE 5

struct Emp get_data();
void print_data(struct Emp[], int); 
double get_average(struct Emp*, int, string);
double get_salary(struct Emp[], string);

struct company_detail
{
	string company_id;
	string company_name;
};
struct Emp
{
	string emp_name;
	string emp_id;
	double salary;
	struct company_detail cmp_detail;
};

int main()
{
	Emp employee[SIZE];
	int entries;
	double salary;
	string name;

	cout << "How many employees do you want to enter?" << endl;
	cin >> entries;
	cin.ignore();

	for (int i = 0; i < entries; i++)
	{
		employee[i] = get_data();
	}

	print_data(employee, entries);

	cout << "Type Employee Name to Get Salary" << endl;
	getline(cin, name);
	salary = get_salary(employee, name);
	if (salary != 0)
	{
		cout << "Salary for " << name << " is $" << salary << endl;
	}
	else
	{
		cout << "Employee could not be found" << endl;
	}

	cout << "Enter Company Name to Find Average Salary" << endl;
	cin >> name;
	salary = get_average(employee, entries, name);
	if (salary != 0)
	{
		cout << "Average Salary for " << name << " is $" << setprecision(10) << salary << endl;
	}
	else
	{
		cout << "Company Could Not Be Found" << endl;
	}

	return 0;
}

struct Emp get_data()
{
	Emp result;

	cout << "Enter Employee Name" << endl;
	getline(cin, result.emp_name);
	cout << "Enter Employee ID" << endl;
	cin >> result.emp_id;
	cout << "Enter Salary" << endl;
	cin >> result.salary;
	cout << "Enter Company ID" << endl;
	cin >> result.cmp_detail.company_id;
	cout << "Enter Company Name" << endl;
	cin.ignore();
	getline(cin, result.cmp_detail.company_name);

	return result;
}

void print_data(Emp employee[], int entries)
{
	for (int i = 0; i < entries; i++)
	{
		cout << "\nEntry Number: " << i + 1 << endl;
		cout << "Employee Name: " << employee[i].emp_name << endl;
		cout << "Employee ID: " << employee[i].emp_id << endl;
		cout << "Salary: " << employee[i].salary << endl;
		cout << "Company ID: " << employee[i].cmp_detail.company_id << endl;
		cout << "Company Name: " << employee[i].cmp_detail.company_name << endl;
	}
}

double get_salary(Emp employee[], string name)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (employee[i].emp_name == name)
			return employee[i].salary;
	}
	return 0;
}

double get_average(Emp * employee, int entries, string name)
{
	double result = 0;
	int count = 0;

	for (int i = 0; i < entries; i++, employee++)
	{
		if (employee->cmp_detail.company_name == name)
		{
			result += employee->salary;
		}
		count++;
	}
	return result/count;
}