/*
Name: Franz Tamani
StuID: 102114822
Unit: SWE20004 - Technical Software Development
Summary: The program takes album details from
		 user and allows them to play music.
*/

#include<iostream>
#include<string>
#include<list>
#include<vector>

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

void add_album(vector<album> &albList)
{
	string name, track, loc;
	int type, amtTrack;
	album alb;

	cout << "\nEnter Album Name: ";
	cin >> name;
	alb.albName = name;
	cout << "Enter Genre: 1. Jap, 2. Eng, 3. Other: ";
	cin >> type;
	//Sets genre accordingly
	switch (type)
	{
	case 1:
		alb.type = Jap;
		break;
	case 2:
		alb.type = Eng;
		break;
	default:
		alb.type = Other;
		break;
	}
	//Get user to enter tracks
	cout << "Enter Number of Tracks 1-5: ";
	cin >> amtTrack;
	//Add amount of tracks to the struct
	alb.trackAmt = amtTrack;
	cout << "Enter the Name of These " << amtTrack << " Tracks" << endl;
	for (int i = 0; i < amtTrack; i++)
	{
		cin.clear();
		cin.ignore();
		//getline(cin, track);
		cin >> track;
		alb.tracks[i] = track;
	}
	//Get user to enter file loc
	cout << "Enter File  Location for These Tracks" << endl;
	cin >> loc;
	alb.trackLoc = loc;
	//Adds Album to list
	albList.push_back(alb);
	//creates a new line, to make console more readable
	cout << endl;
}

void print_all_album(vector<album> &albList)
{
	string gen[3] = { "Jap", "Eng", "Other" };
	for (auto a : albList)
	{
		cout << "\nName of Album: " << a.albName << endl;
		cout << "Genre of Album: " << gen[a.type] << endl;
		cout << "Tracks in Album:" << endl;
		for (int i = 0; i < a.trackAmt; i++)
		{
			cout << a.tracks[i] << endl;
		}
		cout << "Tracks are Located at: " << a.trackLoc << endl << endl;
	}
}

void select_track_to_play(vector<album> &albList)
{
	string name, command;
	album alb;
	int trackNum; 

	cout << "Select an Album to Play: ";
	cin >> name;
	for (auto a : albList)
	{
		if (a.albName == name)
			alb = a;
	}
	cout << "This Album has " << alb.trackAmt << " Tracks:" << endl;
	for (int i = 0; i < alb.trackAmt; i++)
	{
		cout << i + 1 << ". " << alb.tracks[i] << endl;
	}
	cout << "Select Track to Play 1 to " << alb.trackAmt << ": ";
	cin >> trackNum;	//Just reusing variable;
	//Array index starts at 0, we added +1 above, so we subtract 1
	cout << "Track: " << alb.tracks[trackNum - 1] << " from Album: " << alb.albName
		<< " is Now Playing from " << alb.trackLoc << endl << endl;
	command = "start wmplayer.exe -p C:\\" + alb.trackLoc + "\\" + alb.tracks[trackNum - 1] + ".mp3";
	system(command.c_str());
}

int main()
{
	vector<album> albList;
	bool exit = false;
	string command;
	int trackNum;
	unsigned int choice = 0;

	while (!exit)
	{
		switch (choice)
		{
		//Main Menu
		case 0:
			cout << "Choose an Option:" << endl;
			cout << "1. Add an Album" << endl;
			cout << "2. Print Album Details" << endl;
			cout << "3. Play Track From an Album" << endl;
			cout << "4. Exit" << endl;
			cin >> choice;
			break;
		//Enter New Album
		case 1:
			add_album(albList);
			choice = 0; //back to menu when finished
			break;
		//Print Album Details
		case 2:
			print_all_album(albList);
			choice = 0; //back to menu when finished
			break;
		//Play Selected Song
		case 3:
			select_track_to_play(albList);
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