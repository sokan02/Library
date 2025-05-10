//
// Created by sofija on 10/05/25.
//
#include "Library.h"
#include <iostream>
using namespace std;

Library::Library() {
    m_memberList = new MemberList("/home/sofija/Desktop/Library/memberList.txt");
    m_shelf = new Shelf("/home/sofija/Desktop/Library/bookList.txt");
}

Library::~Library() {
    delete m_memberList;
    delete m_shelf;
}

void Library::welcome() {
    cout << "Welcome to the library!\n"
            "Choose an option:\n"
            "1. Register member\n"
            "2. Search for a book\n"
            "3. View all books\n"
            "4. Issue a book\n"
            "5. Return a book\n"
            "6. Add new book to the library\n"
            "7. Exit"<< endl;
}

void Library::run() {
    while(true) {
        welcome();
        cin >> choice;
        if (choice == 7) break;
        unsigned id;
        string title;
        string name;
        switch (choice) {
            case 1:
                cout << "Enter member name: ";
                cin >> name;
                m_memberList->addMember(name);
                break;
            case 2:
                cout << "Enter book title: ";
                cin >> title;
                m_shelf->searchForBooks(title);
                cout << "Press any key to continue" << endl;
                cin >> title;
                break;
            case 3:
                m_shelf->viewBooks();
                cout << "Press any key to continue" << endl;
                cin >> title;
                break;
            case 4:
                cout << "Enter book id: ";
                cin >> id;
                m_shelf->issueBook(m_memberList->getMember(id), id);
                break;
            case 5:
                cout << "Enter book id: ";
                cin >> id;
                m_shelf->returnBook(id);
                break;
            case 6:
                cout << "Enter book title: ";
                cin >> title;
                cout << "Enter book author: ";
                cin >> name;
                m_shelf->addBook(title, name);
                break;
            default:
                cout << "Invalid choice, try again." << endl;
                break;

        }
    }
}