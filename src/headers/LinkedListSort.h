// LinkedListSort.h

#ifndef _LINKED_LIST_SORT_H
#define _LINKED_LIST_SORT_H

#include "SinglyLinkedList.h"
using namespace std;

template <typename T>
void bubblesort(SinglyLinkedList<T> & a,
    bool (* before)(T &, T &));

template <typename T>
bool vectPtr(T &first, T &second);

template <typename T>
bool vectStr(T &first, T &second);

#endif

