#include<iostream>

using namespace std;

struct emp
{
	char* surname;
	int age;
	float salary;
};

int main()
{
	struct emp ricky;
	struct emp* aPtr;
	//Can change struct to have string for name
	//And include string library, but this works too.
	char surname[] = "Peter";
	ricky.surname = surname;
	ricky.age = 35;
	ricky.salary = 2000.53;
	aPtr = &ricky;
	cout << "Surname: " << ricky.surname << "\n" << "Age: " << ricky.
		age << "\n" << "Salary : " << ricky.salary << endl;
	cout << "Surname: " << aPtr->surname << "\n" << "Age: " << (*aPtr).
		age << "\n" << "Salary: " << aPtr->salary;
	return 0;
}
