#include<iostream>
#include<string>

using namespace std;

int main()
{
	int pollutionIndex;
	string rating;
	int j = 0;

	cout << "Enter the pollution index: " << endl;

	cin >> pollutionIndex;

	if (pollutionIndex < 35)
	{
		rating = "Pleasant";
	}
	else if (pollutionIndex >= 35 && pollutionIndex <= 60)
	{
		rating = "Unpleasant";
	}
	else if (pollutionIndex > 60)
	{
		rating = "Hazard";
	}
	else
	{
		cout << "Please Enter a Valid Input..." << endl;
		return 1;	//Exits program as input is invalid.
	}

	/*for (int i = 0; i < 5; i++)
	{
		cout << "The pollution rating is: " << rating << endl;
	}*/
	while (j < 5)
	{
		cout << "The pollution rating is: " << rating << endl;
		j++;
	}
}