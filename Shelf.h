//
// Created by sofija on 10/05/25.
//

#ifndef SHELF_H
#define SHELF_H
#include "Book.h"
#include "Reader.h"
#include<vector>
#include<iostream>

using namespace std;


class Shelf {
public:
    Shelf(string filepath);
    ~Shelf();
    void searchForBooks(string title);
    Book* getBook(unsigned id);
    void viewBooks();
    void addBook(string title, string author);
    void issueBook(Member* holder, unsigned id);
    void returnBook(unsigned id);
    void document();
private:
    vector<Book*> m_books;
    bool isSubstring(string str, string substr);
    unsigned m_idLastBook;
};



#endif //SHELF_H
