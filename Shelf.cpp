//
// Created by sofija on 10/05/25.
//
#include "Shelf.h"
#include "Parser.h"

Shelf::Shelf(string filepath) {
    Parser* parser = new ParserA(new FileReader(filepath));
    Book* book;
    m_idLastBook = 1;
    while ((book = parser->getNextBook()) != nullptr) {
        m_books.push_back(book);
        m_idLastBook++;
    }
    delete parser;
}

Shelf::~Shelf() {
    for(Book* book : m_books) {
        delete book;
    }
}

void Shelf::searchForBooks(string title) {
    for(Book* currBook : m_books) {
        if(isSubstring(currBook->getTitle(), title)) {
            currBook->bookDisplay();
        }
    }
}

bool Shelf::isSubstring(string str, string substr) {
    int n = str.length();
    int m = substr.length();

    // Iterate through txt
    for (int i = 0; i <= n - m; i++) {

        // Check for substring match
        int j;
        for (j = 0; j < m; j++) {

            // Mismatch found
            if (str[i + j] != substr[j]) {
                break;
            }
        }

        // If we completed the inner loop, we found a match
        if (j == m) {

            // Return starting index
            return true;
        }
    }

    // No match found
    return false;
}

Book* Shelf::getBook(unsigned id) {
    for(Book* book : m_books) {
        if(book->getId() == id) {
            return book;
        }
    }
    return nullptr;
}

void Shelf::viewBooks() {
    cout << "\t\t\t\tBooks in library:" << endl;
    for(Book* book : m_books) {
        book->bookDisplay();
    }
}

void Shelf::addBook(string title, string author) {
    m_books.push_back(new Book(title, author, m_idLastBook, 0, "", true));
    ofstream booksFile("/home/sofija/Desktop/Library/bookList.txt", std::ios_base::app);
    booksFile << "\"" << title << "\"," << author << "," << m_idLastBook << ","  << 0 << "," << "Noone"<< ",true"<< "\n";
    booksFile.close();
    m_idLastBook++;
}

void Shelf::issueBook(Member* holder, unsigned id) {
    Book* book = getBook(id);
    if (book->getAvailable()) {
        book->issueBook(holder);
    }
    document();
}

void Shelf::returnBook(unsigned id) {
    Book* book = getBook(id);
    if (book->getHolderId() == 0) return;
    book->returnBook();
    document();
}

void Shelf::document() {
    ofstream booksFile("/home/sofija/Desktop/Library/bookList.txt");
    for (Book* book : m_books) {
        booksFile << "\"" << book->getTitle() << "\"," << book->getAuthor() << "," << book->getId() << ","  << book->getHolderId() << "," << book->getHolderName() << ","<< book->getAvailable() << "\n";
    };
    booksFile.close();
}
