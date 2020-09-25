/*
Name: Franz Tamani
StuID: 102114822
Unit: SWE20004 - Technical Software Development
Summary: The program creates 5 studentname structs
		 and stores them in a linked in alphabetical 
		 order, it then prints them.
*/
#include<iostream>

using namespace std;

struct studentname
{
	char letter;
	struct studentname* next;
};

typedef struct studentname STUDENTName;
typedef STUDENTName* STUDENTNamePtr;

int main()
{
	STUDENTNamePtr s1 = new STUDENTName;
	STUDENTNamePtr s2 = new STUDENTName;
	STUDENTNamePtr s3 = new STUDENTName;
	STUDENTNamePtr s4 = new STUDENTName;
	STUDENTNamePtr s5 = new STUDENTName;
	s1->letter = 'T';
	s2->letter = 'a';
	s3->letter = 'm';
	s4->letter = 'a';
	s5->letter = 'n';

	s2->next = s4;
	s4->next = s3;
	s3->next = s5;
	s5->next = s1;
	s1->next = NULL;

	STUDENTNamePtr current = s2;
	while (current != NULL)
	{
		cout << current->letter;
		if (current->next != NULL)
			cout << " -> ";
		current = current->next;
	}
	return 0;
}