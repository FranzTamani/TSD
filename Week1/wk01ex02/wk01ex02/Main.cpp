#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	char name[50]; // Max of 50 characters in a name
	int count;

	cout << "Type in your name" << endl;
	cin >> name;
	cout << "How many greetings: " << endl;
	cin >> count;
	if (cin.fail()) {
		cout << "Enter valid number" << endl;
		return 0;
	}
	else {
		for (int i = 0; i < count; i++) {
			cout << "Welcome to my world! " << name << endl;
		}
	}
	cin.ignore();
	cin.get();
	return 0;
}
