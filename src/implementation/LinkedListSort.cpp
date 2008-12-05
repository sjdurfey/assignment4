////////////////////////////////////////
// LinkedListSort.cpp

#include <iostream>
#include "/home/stephen/workspace/assgn4/src/headers/LinkedListSort.h"
using namespace std;

//a bubble sort that takes in the list to be sorted, and a function pointer to augment
//the code depending on the type of data being stored in the list (either vector of vector strings,
//or a vector or pointers to a vector of strings.
template <typename T>
void bubblesort(SinglyLinkedList<T> & A, bool (* before)(T &, T &))
{
	T temp; //used for swapping values
    typename SinglyLinkedList<T>::iterator it1;
    typename SinglyLinkedList<T>::iterator it2;
    bool swapped;

    do
    {
       swapped = false;
       it1 = it2 = A.begin();
       ++it2;
       while((it2 != A.end()))
       {
    	   if((*before)(*it1,*it2))// Swaps if before returns true
           {
        	    temp = *it1;
                *it1 = *it2;
                *it2 = temp;
                swapped=true;
            }
            ++it1;
            ++it2;
       }

    } while(swapped);
}

//returns a bool value based on the evaluation of two integers as returned
//by the function stringToInt. true if greater than, false if less than.
//this particular function is only used by a vector of pointers to strings
template <typename T>
bool vectPtr(T &first, T &second)
{
  return stringToInt((*first)[9]) > stringToInt((*second)[9]);
}

//returns a bool value based on the evaluation of two integers as returned
//by the function stringToInt. true if greater than, false if less than.
//this particular function is only used by a vector of strings.
template <typename T>
bool vectStr(T &first, T &second)
{
  return (stringToInt(first[9]) > stringToInt(second[9]));
}

