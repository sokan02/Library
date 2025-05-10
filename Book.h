#ifndef BOOK_H
#define BOOK_H

#include<string>
using namespace std;

class Member;

class Book
{
public:
    Book(string title, string author, unsigned id, unsigned holderId, string holderName, bool available);

    void setTitle(string title);
    string getTitle();

    void setAuthor(string author);
    string getAuthor();

    void setId(unsigned id);
    unsigned getId();

    void setHolderId(unsigned id);
    unsigned getHolderId();

    void setHolderName(string name);
    string getHolderName();

    void setAvailable(bool available);
    bool getAvailable();

    void issueBook(Member* holder);
    void returnBook();

    void bookDisplay();

private:
    string m_title;
    string m_author;
    unsigned m_id;
    bool m_available;
    string m_holderName;
    unsigned m_holderId;


};


#endif