#include <iostream>
#include <limits>
#include <string>
#include "CircularLinkedList.h"
#include "CreateBook.h"

using namespace std;

int main()
{
    CircularLinkedList library;

    library.Insert(CreateBook(103, "Operating Systems"));
    library.Insert(CreateBook(101, "Data Structures"));
    library.Insert(CreateBook(105, "Computer Networks"));

    int choice, id, index, first, second;
    string title;

    do
    {
        cout << "\n===== CIRCULAR LIBRARY BOOK DISPLAY =====\n";
        cout << "1. Display All Books\n";
        cout << "2. Insert Book at Head\n";
        cout << "3. Remove Book from Head\n";
        cout << "4. Insert Book at Index\n";
        cout << "5. Remove Book at Index\n";
        cout << "6. Swap Books\n";
        cout << "7. Sort Books by ID\n";
        cout << "8. Reverse Book Collection\n";
        cout << "9. Move to Next Book\n";
        cout << "10. Check Collection Status\n";
        cout << "11. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            library.Print();
            break;

        case 2:
            cout << "Enter book ID: ";
            cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter book title: ";
            getline(cin, title);

            library.Insert(CreateBook(id, title));
            cout << "Book inserted.\n";
            break;

        case 3:
        {
            BookNode* removed = library.Remove();

            if (removed != nullptr)
            {
                cout << "Removed: " << removed->title << endl;
                delete removed;
            }
            else
                cout << "Collection is empty.\n";

            break;
        }

        case 4:
            cout << "Enter book ID: ";
            cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter book title: ";
            getline(cin, title);
            cout << "Enter index (starting from 0): ";
            cin >> index;

            library.InsertAt(CreateBook(id, title), index);
            cout << "Book inserted.\n";
            break;

        case 5:
        {
            cout << "Enter index: ";
            cin >> index;

            BookNode* removed = library.RemoveAt(index);

            if (removed != nullptr)
            {
                cout << "Removed: " << removed->title << endl;
                delete removed;
            }
            else
                cout << "Collection is empty.\n";

            break;
        }

        case 6:
            cout << "Enter first index: ";
            cin >> first;
            cout << "Enter second index: ";
            cin >> second;
            library.Swap(first, second);
            break;

        case 7:
            library.Sort();
            cout << "Books sorted by ID.\n";
            break;

        case 8:
            library.Reverse();
            cout << "Collection reversed.\n";
            break;

        case 9:
            library.MoveNext();
            break;

        case 10:
            if (library.IsEmpty())
                cout << "Collection is empty.\n";
            else
                cout << "Collection is not empty.\n";
            break;

        case 11:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 11);

    return 0;
}
