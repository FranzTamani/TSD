#include<iostream>

using namespace std;


//Calculates the products and sum of 3 integers
int main(int argc, char const *argv[])
{
	int x, y, z, sum, product;
	cout << "Enter 3 numbers" << endl;
	cout << "Enter the first number: ";
	cin >> x;
	cout << "Enter the second number: ";
	cin >> y;
	cout << "Enter the third number: ";
	cin >> z;
	sum = x + y + z; //Adds all the 3 integers
	product = x * y * z; //Adds all the 3 integers
	cout << "The sum is " << sum << endl;
	cout << "The product is " << product << endl;
	cin.ignore();
	cin.get();
	return 0;
}
