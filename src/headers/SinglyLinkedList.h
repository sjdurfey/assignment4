////////////////////////////////////////
// SinglyLinkedList.h

#ifndef _SINGLY_LINKED_LIST_H
#define _SINGLY_LINKED_LIST_H

template <typename T>
class SinglyLinkedList
{
private:
    class Node
    {
    public:
        T       value;
        Node    *next;
    };

    Node    *head, *tail;
    int     len;

public:
    SinglyLinkedList();
    int size() const;

    class iterator
    {
    public:
        iterator operator++();
        bool operator!=(const iterator & it2) const;
        T & operator*();
        Node    *ptr;
    };

    iterator begin();
    iterator end();


    void push_front(const T & x);
    void pop_front_push_other_front(SinglyLinkedList & y);
    void append_clear_other(SinglyLinkedList & y);
};
#endif

