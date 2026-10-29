#include <iostream>
#include <utility>
#include "CircularLinkedList.h"

using namespace std;

CircularLinkedList::CircularLinkedList()
{
    tail = nullptr;
    current = nullptr;
    count = 0;
}

CircularLinkedList::~CircularLinkedList()
{
    while (!IsEmpty())
    {
        BookNode* book = Remove();
        delete book;
    }
}

bool CircularLinkedList::IsEmpty()
{
    return count == 0;
}

bool CircularLinkedList::IsNotEmpty()
{
    return count > 0;
}

void CircularLinkedList::ResetCurrent()
{
    current = nullptr;
}

BookNode* CircularLinkedList::GetNodeAt(int index)
{
    if (IsEmpty())
        return nullptr;

    BookNode* temp = tail->next;

    for (int i = 0; i < index; i++)
        temp = temp->next;

    return temp;
}

void CircularLinkedList::Insert(BookNode* book)
{
    if (book == nullptr)
        return;

    if (IsEmpty())
    {
        tail = book;
        book->next = book;
    }
    else
    {
        book->next = tail->next;
        tail->next = book;
    }

    count++;
    ResetCurrent();
}

BookNode* CircularLinkedList::Remove()
{
    if (IsEmpty())
        return nullptr;

    BookNode* first = tail->next;

    if (count == 1)
        tail = nullptr;
    else
        tail->next = first->next;

    first->next = nullptr;
    count--;
    ResetCurrent();

    return first;
}

void CircularLinkedList::InsertAt(BookNode* book, int index)
{
    if (book == nullptr)
        return;

    if (IsEmpty() || index <= 0)
    {
        Insert(book);
        return;
    }

    if (index >= count)
    {
        book->next = tail->next;
        tail->next = book;
        tail = book;
        count++;
        ResetCurrent();
        return;
    }

    BookNode* previous = GetNodeAt(index - 1);

    book->next = previous->next;
    previous->next = book;

    count++;
    ResetCurrent();
}

BookNode* CircularLinkedList::RemoveAt(int index)
{
    if (IsEmpty())
        return nullptr;

    if (index <= 0)
        return Remove();

    if (index >= count)
        index = count - 1;

    BookNode* previous = GetNodeAt(index - 1);
    BookNode* removed = previous->next;

    previous->next = removed->next;

    if (removed == tail)
        tail = previous;

    removed->next = nullptr;
    count--;
    ResetCurrent();

    return removed;
}

void CircularLinkedList::Swap(int first, int second)
{
    if (first < 0 || second < 0 ||
        first >= count || second >= count)
    {
        cout << "Invalid index!\n";
        return;
    }

    BookNode* a = GetNodeAt(first);
    BookNode* b = GetNodeAt(second);

    swap(a->bookID, b->bookID);
    swap(a->title, b->title);
    ResetCurrent();
}

void CircularLinkedList::Sort()
{
    if (count < 2)
        return;

    for (int i = 0; i < count - 1; i++)
    {
        BookNode* a = tail->next;

        for (int j = 0; j < count - i - 1; j++)
        {
            BookNode* b = a->next;

            if (a->bookID > b->bookID)
            {
                swap(a->bookID, b->bookID);
                swap(a->title, b->title);
            }

            a = a->next;
        }
    }

    ResetCurrent();
}

void CircularLinkedList::Reverse()
{
    if (count < 2)
        return;

    BookNode* oldFirst = tail->next;
    BookNode* previous = tail;
    BookNode* currentNode = oldFirst;

    for (int i = 0; i < count; i++)
    {
        BookNode* nextNode = currentNode->next;
        currentNode->next = previous;
        previous = currentNode;
        currentNode = nextNode;
    }

    tail = oldFirst;
    ResetCurrent();
}

void CircularLinkedList::Print()
{
    if (IsEmpty())
    {
        cout << "No books available.\n";
        return;
    }

    BookNode* temp = tail->next;

    cout << "\n--- Book Collection ---\n";

    for (int i = 0; i < count; i++)
    {
        cout << "ID: " << temp->bookID
             << " | Title: " << temp->title << endl;

        temp = temp->next;
    }

    cout << "Total Books: " << count << endl;
}

void CircularLinkedList::MoveNext()
{
    if (IsEmpty())
    {
        cout << "No books available.\n";
        return;
    }

    if (current == nullptr)
        current = tail->next;
    else
        current = current->next;

    cout << "Current Book: " << current->title
         << " (ID: " << current->bookID << ")\n";
}