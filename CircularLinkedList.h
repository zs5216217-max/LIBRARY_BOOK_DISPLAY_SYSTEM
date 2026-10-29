#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include "BookNode.h"

class CircularLinkedList
{
private:
    BookNode* tail;
    BookNode* current;
    int count;

    BookNode* GetNodeAt(int index);
    void ResetCurrent();

public:
    CircularLinkedList();
    ~CircularLinkedList();

    bool IsEmpty();
    bool IsNotEmpty();

    void Insert(BookNode* book);
    BookNode* Remove();

    void InsertAt(BookNode* book, int index);
    BookNode* RemoveAt(int index);

    void Swap(int first, int second);
    void Sort();
    void Reverse();
    void Print();
    void MoveNext();
};

#endif