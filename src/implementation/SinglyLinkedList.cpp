////////////////////////////////////////
// SinglyLinkedList.cpp

#include "/home/stephen/workspace/assgn4/src/headers/SinglyLinkedList.h"
#include "/home/stephen/workspace/assgn4/src/headers/stringUtil.h"
using namespace std;

////////////////////////////////////////

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList()
{
    len = 0;
    head=NULL;
    tail=NULL;
}

template <typename T>
int SinglyLinkedList<T>::size() const
{
    return len;
}

////////////////////////////////////////

// Assigns the iterator to the next Node
// and returns that iterator.
template <typename T>
typename SinglyLinkedList<T>::iterator
    SinglyLinkedList<T>::iterator::operator++()
{
	  ptr = ptr->next;
	  return *this;
}

// Compares two iterators and returns true
// or false depending on whether or not they
// are referencing the same Node.
template <typename T>
bool SinglyLinkedList<T>::iterator::operator!=(
    const SinglyLinkedList<T>::iterator & it2) const
{

  return ptr != it2.ptr;

}

// Returns the value of the Node that the iterator
// is referencing.
template <typename T>
T & SinglyLinkedList<T>::iterator::operator*()
{
    return ptr->value;

}

////////////////////////////////////////

template <typename T>
typename SinglyLinkedList<T>::iterator SinglyLinkedList<T>::begin()
{
  typename SinglyLinkedList<T>::iterator temp;
  temp.ptr = head;
  return temp;

}

template <typename T>
typename SinglyLinkedList<T>::iterator SinglyLinkedList<T>::end()
{
  typename SinglyLinkedList<T>::iterator temp;
  temp.ptr = tail->next;
  return temp;
}

template <typename T>
void SinglyLinkedList<T>::push_front(const T & x)
{
  Node* temp = new Node;
  temp->value = x;
  temp->next = head;
  head = temp;
  if(len == 0)
  {
    tail = head;
  }
  len++;
}



/* TO BE CODED AT A LATER DATE *********************************
template <typename T>
void SinglyLinkedList<T>::pop_front_push_other_front(
SinglyLinkedList<T> & y)
{

}

template <typename T>
void SinglyLinkedList<T>::append_clear_other(
SinglyLinkedList<T> & y)
{

}

******************************* TO BE CODED AT A LATER DATE */



