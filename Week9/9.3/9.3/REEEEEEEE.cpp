/*
Name: Franz Tamani
StuID: 102114822
Unit: SWE20004 - Technical Software Development
Summary: Allows the user to create albums
		 and lets them play music.
*/

#include<iostream>
#include<string>
#include<list>

#pragma comment(lib, "winmm.lib")

using namespace std;

enum genre { Jap, Eng, Other };

struct album
{
	string albName;
	genre type;
	int trackAmt;
	string tracks[5];
	string trackLoc;
};

int main()
{
	album alb;
	string gen[3] = { "Jap", "Eng", "Other" };	//Used for printing
	bool exit = false;
	string name, command;
	int track, type, amtTrack, albums;
	unsigned int choice = 0;

	//Initial Setup
	cout << "Many Many Albums are there? ";
	cin >> albums;
	album* albPtr = new album[albums];
	int albCount = 0;

	while (!exit)
	{
		switch (choice)
		{
		//Main Menu
		case 0:
			cout << "\nChoose an Option:" << endl;
			cout << "1. Add an Album" << endl;
			cout << "2. Print Album Details" << endl;
			cout << "3. Play Track From an Album" << endl;
			cout << "4. Exit" << endl;
			cin >> choice;
			break;
		//Enter New Album
		case 1:
			if (albCount >= albums)
			{
				cout << "Maximum Amount of Albums Reached!!!" << endl;
				choice = 0;
				break;
			}
			cout << "Enter Album Name: ";
			cin >> albPtr[albCount].albName;
			cout << "Enter Genre: 1. Jap, 2. Eng, 3. Other: ";
			cin >> type;
			//Sets genre accordingly
			switch (type)
			{
			case 1:
				albPtr[albCount].type = Jap;
				break;
			case 2:
				albPtr[albCount].type = Eng;
				break;
			default:
				albPtr[albCount].type = Other;
				break;
			}
			//Get user to enter tracks
			cout << "Enter Number of Tracks 1-5: ";
			cin >> albPtr[albCount].trackAmt;
			amtTrack = albPtr[albCount].trackAmt;
			cout << "Enter the Name of These " << amtTrack << " Tracks" << endl;
			for (int i = 0; i < amtTrack; i++)
			{
				cin.clear();
				cin.ignore();
				cin >> albPtr[albCount].tracks[i];
			}
			//Get user to enter file loc
			cout << "Enter File  Location for These Tracks" << endl;
			cin >> albPtr[albCount].trackLoc;
			//Next Instance
			albCount++;
			choice = 0; //back to menu when finished
			break;
		//Print Album Details
		case 2:
			for (int i = 0; i < albCount; i++)
			{
				cout << "\nName of Album: " << albPtr[i].albName << endl;
				cout << "Genre of Album: " << gen[albPtr[i].type] << endl;
				cout << "Tracks in Album:" << endl;
				for (int j = 0; j < albPtr[i].trackAmt; j++)
				{
					cout << albPtr[i].tracks[j] << endl;
				}
				cout << "Tracks are Located at: " << albPtr[i].trackLoc << endl;
			}
			choice = 0; //back to menu when finished
			break;
		//Play Selected Song
		case 3:
			cout << "Select an Album to Play: ";
			cin >> name;
			for (int i = 0; i < albCount; i++)
			{
				if (albPtr[i].albName == name)
					alb = albPtr[i];
			}
			cout << "This Album has " << alb.trackAmt << " Tracks:" << endl;
			for (int i = 0; i < alb.trackAmt; i++)
			{
				cout << i + 1 << ". " << alb.tracks[i] << endl;
			}
			cout << "Select Track to Play 1 to " << alb.trackAmt << ": ";
			cin >> track;
			//Array index starts at 0, we added +1 above, so we subtract 1
			cout << "Track: " << alb.tracks[track - 1] << " from Album: " << alb.albName
				<< "is Now Playing from" << alb.trackLoc << endl;
			command = "start wmplayer.exe -p C:\\" + alb.trackLoc + "\\" + alb.tracks[track - 1] + ".mp3";
			system(command.c_str());
			choice = 0; //back to menu when finished
			break;
		//Exit Application
		case 4:
			exit = true;
			break;
		//Used for errors when inputting choice
		default:
			choice = 0;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!!!" << endl;
			break;
		}
	}
	return 0;
}