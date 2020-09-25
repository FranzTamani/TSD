/*
Name: Franz Tamani
StuID: 102114822
Unit: SWE20004 - Technical Software Development
Summary: Reads from a file to find minimum,
		 maximum, total and average pricing
		 and writes it to a file.
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream inFile;		//input file price.dat
	ofstream outFile;		//output file output.dat
	inFile.open("price.dat");

	if (inFile.fail())
	{
		cout << "Input File - ERROR!!!" << endl;
		exit(1);	//1 - define input file error
	}

	int count, i;
	double id, price, max, min, avg, total;

	inFile >> count;
	for (i = 0; i < count; i++)
	{
		inFile >> id >> price;
		if (i == 0)
			total = min = max = price;
		if (price > max)
			max = price;
		if (price < min)
			min = price;

		total += price;
	}
	inFile.close();	//Closes input file

	outFile.open("output.dat");

	if (outFile.fail())
	{
		cout << "Output File - ERROR!!!" << endl;
		exit(2);	//2 - define output file error
	}

	avg = (total / count);

	outFile << "Number of price readings: " << count << endl;
	outFile << "Maximum price: " << max << endl;
	outFile << "Minimum price: " << min << endl;
	outFile << "Average price: " << avg << endl;
	outFile.close();	//Closes output file

	return 0;
}