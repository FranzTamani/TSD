#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	const int maxChar = 10;
	string serialNum; //serial number
	string userName; //User name
	string empName; //Employee name
	char pcType; //PC Type
	int coreNum; //Number of cores
	double cpuFreq; //CPU Frequency
	string macAddress; //MAC address
	unsigned int IP; //IP address
	short int IP_part_1;
	short int IP_part_2;
	short int IP_part_3;
	short int IP_part_4;

	cout << "Please enter the user name: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, userName);

	cout << "Please enter the employee name: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, empName);

	cout << "Please enter the PC serial number (max 10 characters): ";
	cin >> serialNum;
	
	if (serialNum.size() > maxChar)
	{
		cout << "Exceeded maximum characters." << endl;
		return 1;
	}

	cout << "Please enter the PC type (S = Server, D = Desktop, L = Laptop, T= Tablet, P= Phone): ";
	cin >> pcType;

	cout << "Please enter the number of cores: ";
	cin >> coreNum;

	cout << "Please enter the CPU speed (Ghz): ";
	cin >> cpuFreq;

	cout << "Please enter the MAC address: ";
	cin >> macAddress;

	cout << "Please enter the IPV4 address without the dots (e.g. 111 222 333 444): ";
	cin >> IP_part_1 >> IP_part_2 >> IP_part_3 >> IP_part_4;
	
	IP = IP_part_1 * pow(256., 3) + IP_part_2 * pow(256., 2) + IP_part_3 * 256 + IP_part_4;


	cout << "| " << "User: " << setw(10) << userName << " |" << setw(10) << "Employee: " << empName << " |"
	<< "Serial: " << setw(7) << serialNum << " | " << "Type:" << setw(6) << pcType << 
	"|" << "Cores: " << coreNum << setw(6) << " | " << "Speed:" << cpuFreq << "Ghz" << " |" << endl;

	cout << "|" << setw(6) << "MAC:" << macAddress << "|" << "IP:" << IP_part_1 << "." << IP_part_2 << "." << IP_part_3 << "." << IP_part_4
		<< " | " << "IP address as integer:" << IP << endl;

	system("pause");
	return 0;


}