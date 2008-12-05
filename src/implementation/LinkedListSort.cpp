////////////////////////////////////////
// LinkedListSort.cpp

#include <iostream>
#include "/home/stephen/workspace/assgn4/src/headers/LinkedListSort.h"
using namespace std;

template <typename T>
void bubblesort(SinglyLinkedList<T> & A, bool (* before)(T &, T &))
{

    T temp;
    typename SinglyLinkedList<T>::iterator it1;
    typename SinglyLinkedList<T>::iterator it2;
    int j;
    int initial_size = A.size();
    bool swapped=false;

    do {
       j=0;
       swapped = false;
       it1 = it2 = A.begin();
       ++it2;
       while((it2 != A.end()) && j<initial_size){


           if((*before)(*it1,*it2)){ // Swaps if before returns true

                temp = *it1;
                *it1 = *it2;
                *it2 = temp;
                swapped=true;
            }
            ++it1;
            ++it2;
            ++j;
       }

    } while(swapped);
}

template <typename T>
bool vectPtr(T &first, T &second)
{
  return stringToInt((*first)[9]) > stringToInt((*second)[9]);
}

template <typename T>
bool vectStr(T &first, T &second)
{
  return (stringToInt(first[9]) > stringToInt(second[9]));
}

