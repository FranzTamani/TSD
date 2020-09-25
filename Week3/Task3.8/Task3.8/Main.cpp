////////////////////////////////////
////Name: Franz Jordaneal Tamani////
////StuID: 102114822		    ////
////////////////////////////////////
#include<iostream>
#include<cmath>
#include<string>
#include<iomanip>

using namespace std;

int main()
{
	string user, employee, macAddress, pcSerial;
	short int  ip1, ip2, ip3, ip4, cores;
	char pcType;
	double cpuSpeed;
	unsigned int IP;

	cout << "Please enter the user name: ";
	getline(cin, user);								//User can have space in it
	cout << "Please enter the employee name: ";
	getline(cin, employee);							//employee name can have space in it

	cout << "Please enter the PC serial number (max 10 characters): ";
	cin >> pcSerial;
	cout << "Please enter the PC type (S = Server, D = Desktop, L = Laptop, T = Tablet, P = Phone): ";
	cin >> pcType;
	cout << "Please enter the number of cores: ";
	cin >> cores;
	cout << "Please enter the CPU speed (GHz): ";
	cin >> cpuSpeed;
	cout << "Please enter MAC Address: ";
	cin >> macAddress;
	cout << "Please enter IPV4 without dots (e.g. 102 192 168 1): ";
	cin >> ip1 >> ip2 >> ip3 >> ip4;

	//cout << "ip1 = " << ip1 << "ip2 = " << ip2 << "ip3 = " << ip3 << "ip4 = " << ip4 << endl;

	IP = ip1 * pow(256.0, 3) + ip2 * pow(256.0, 2) + ip3 * 256.0 + ip4;

	cout << "+" << setfill('=') << setw(78) << "+" << endl;
	cout << setfill(' ');
	cout << "| User:" << setw(10) << user;							
	cout << "| Employee:" << setw(24) << employee;					
	cout << "| Serial:"  << setw(15) << pcSerial << " |" << endl;

	cout << "+" << setfill('-') << setw(78) << "+" << endl;
	cout << setfill(' ');
	cout << "| Type:" << setw(5) << pcType;
	cout << "| Cores:" << setw(5) << cores;
	cout << "| Speed:" << setw(5) << cpuSpeed;
	cout << "| MAC:" << setw(16) << macAddress;
	cout << "| IP:" << ip1 << "." << ip2 << "." << ip3 << "." << ip4 << " |" << endl;

	cout << "+" << setfill('-') << setw(78) << "+" << endl;
	cout << setfill(' ');
	cout << "|" << setw(21) << " ";
	cout << "IP address as integer:" << IP;
	cout << setw(23) << "|" << endl;

	cout << "+" << setfill('=') << setw(78) << "+" << endl;
}