#include<iostream>

using namespace std;


//Calculates the products of 3 integers
int main(int argc, char const *argv[])
{
	int x, y, z, result;
	cout << "Enter 3 numbers" << endl;
	cout << "Enter the first number: ";
	cin >> x;
	cout << "Enter the second number: ";
	cin >> y;
	cout << "Enter the third number: ";
	cin >> z;
	result = x * y * z; //Multiplies all of the numbers
	cout << "The product is " << result << endl;
	cin.ignore();
	cin.get();
	return 0;
}
