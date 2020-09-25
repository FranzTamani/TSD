#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#define SIZE 20
void frequent (int x[])
{
	int i,max=0,mode=0;
	int fre[100]={0};//all values of array initialised with 0 
	for(i=0;i<SIZE;i++) 
		++fre[x[i]]; //count the occurence of each number 
	for(i=0;i<100;i++) //loop to find most frequent number 
	if(fre[i]>max)
	{
		max=fre[i];
		mode=i;
	}
	cout<<"The most frequent number is "<<mode<<" occuring "<< fre[mode]<<" times\n";
}

int main()
{
	int check,k,x[SIZE],i;
	srand(time(NULL));
	for(i=0;i<SIZE;i++) //read in 20 numbers 
	{
		check=0; //flag for printing duplicate
		x[i]=rand()%100; //generate number between 0 and 99
		for(k=0;k<i;k++)  //loop for checking duplicate 
			if(x[i]==x[k]) //checking duplicate 
				check=1; //if duplicate change the flag value to 1 
		if(check==1) //if flag value is 1, then that number is a duplicate number 
			cout<<x[i] <<" is a duplicate number \n";
		else //if the flag value is 0 then it is not a duplicate number 
			cout<<x[i]<<endl;	//print the array element 
	}
	frequent(x); //function to find most frequent number 
}