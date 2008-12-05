////////////////////////////////////////
// LinkedListSortTester.cpp
#include <sys/types.h>
#include <sys/times.h>
#include <sys/param.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cstring>
#include "/home/stephen/workspace/assgn4/src/headers/stringUtil.h"
#include "SinglyLinkedList.cpp"
#include "LinkedListSort.cpp"

using namespace std;


int main(int argc, char *argv[])
{
    double timeI, timeII;
    struct tms t, u;
    long t1, t2;
    int i = 0;

    ifstream infile(argv[1]);

    string arguments = argv[2];

    if(argc != 3 || *argv[2] != '-' || strlen(argv[2]) != 3 )
    {
      cout << "Invalid options and/or not enough arguments\n";
      cout << "Program usage: ./ourSort [input file] [sort options][-l linked list, -v vector of string, -p vector of pointers]\n";
      return 0;
    }

	//if clause for a specified linked list with vectors of strings
    if((arguments[1] == 'l' && arguments[2] == 'v') || (arguments[1] == 'v' && arguments[2] == 'l'))
    {
    	SinglyLinkedList <vector<string> > list;
    	SinglyLinkedList<vector<string> >::iterator it1;
    	vector<string> row;
    	double sum = 0;

    	//creates the linked list in the list object
    	while(readMultiwordVector(row, infile))
    	{
    		list.push_front(row);
    	}

    	t1 = times(&t);
    	bubblesort(list, vectStr);
    	t2 = times(&u);   // ** t1 & t2 are a stopwatch for # of ticks in this segement of code
    	//below divides the number of clock ticks taken to generate the numbers by
    	// HZ which is the number of clock ticks/sec (a system defined number)
    	timeI = (double)(u.tms_utime-t.tms_stime)/(HZ);  // #ofTicks/HZ(processor speed)

    	it1 = list.begin();
    	//while loop prints out first 100 sorted entries in list
    	while(i < 100)
    	{
    		for(int index = 0; index < 10; index++)
    	    {
    			cout << (*it1)[index] << " ";
    	    }
    	    ++it1;
    	    i++;
    	   cout << endl;
    	}

    	it1 = list.begin();
    	i = 0;
    	while(it1 != list.end())//while loop that sums the size of the entire list
    	{
    		sum += double(sizeof((*it1))); //finds the size of the vector
    		++it1;
    	}
    	cout << "Size: " << (sum/1000) << "KB" << endl;

    	cout << fixed << setprecision(2) << timeI << "seconds" << endl;
    }
    //if clause for a specified linked list with pointers to a vector of strings
    else if((arguments[1] = 'l' && arguments[2] == 'p') || (arguments[1] == 'p' && arguments[2] == 'l'))
    {
    	SinglyLinkedList <vector<string>* > list; //creates a list of pointers to vectors of strings
    	SinglyLinkedList<vector<string>* >::iterator it1; //iterator to traverse the list
    	vector<string> row;
    	double sum = 0;

    	//this while loop builds the entire list
    	while(readMultiwordVector(row, infile))
    	{
    		vector<string>* ptrVect = new vector<string>(row);
    		list.push_front(ptrVect);
    	}
    	t1 = times(&t);
    	bubblesort(list, vectPtr);
    	t2 = times(&u);   // ** t1 & t2 are a stopwatch for # of ticks in this segement of code
    	//below divides the number of clock ticks taken to generate the numbers by
    	// HZ which is the number of clock ticks/sec (a system defined number)
    	timeI = (double)(u.tms_utime-t.tms_stime)/(HZ);  // #ofTicks/HZ(processor speed)
    	it1 = list.begin();

    	//while loop prints out first 100 sorted entries in list
    	while(i < 100)
    	{
    		for(int index = 0; index < 10; index++)
    	    {
    			cout << (*(*it1))[index] << " ";
    	    }
    	    ++it1;
    	    i++;
    	    cout << endl;
    	}


    	it1 = list.begin(); //resets iterator to beginning
    	while(it1 != list.end()) //while loop that sums the size of the entire list
    	{
    		//finds the size of the pointer in the iterator and the size of the vector it is pointing to.
    		sum += double(sizeof((*it1))) + double(sizeof((*(*it1))));
    	    ++it1;
    	}

    	cout << "Size: " << (sum/1000) << "KB" << endl;

    	cout << fixed << setprecision(2) << timeI << "seconds" << endl;
    }
    else
    {
    	cout << "Invalid options and/or not enough arguments\n";
    	cout << "Program usage: ./ourSort [input file] [sort options][-l linked list, -v vector of string, -p vector of pointers]\n";
    }

    return 0;
}
