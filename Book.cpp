#include "Book.h"
#include "Member.h"
#include <fstream>
#include <iostream>

Book::Book(string title, string author, unsigned id, unsigned holderId, string holderName, bool available) : m_title(title), m_author(author), m_id(id), m_holderId(holderId), m_holderName(holderName), m_available(available)
{}


void Book::setTitle(string title)
{
    this->m_title = title;
}

string Book::getTitle()
{
    return this->m_title;
}

void Book::setAuthor(string author)
{
    this->m_author = author;
}

string Book::getAuthor()
{
    return this->m_author;
}

void Book::setId(unsigned id)
{
    this->m_id = id;
}

unsigned Book::getId()
{
    return this->m_id;
}

void Book::issueBook(Member* holder)
{
    this->m_available = false;
    this->m_holderId = holder->getId();
    this->m_holderName = holder->getName();
    
}

void Book::returnBook()
{
    this->m_available = true;
    this->m_holderName = "Noone";
    this->m_holderId = 0;
}

void Book::setHolderId(unsigned id)
{
    this->m_holderId = id;
}

unsigned Book::getHolderId()
{
    return this->m_holderId;
}

void Book::setHolderName(string name)
{
    this->m_holderName = name;
}

string Book::getHolderName()
{
    return this->m_holderName;
}

void Book::setAvailable(bool available)
{
    this->m_available = available;
}

bool Book::getAvailable()
{
    return this->m_available;
}

void Book::bookDisplay() {
    string available = m_available ? "Yes" : "No";
    cout << m_id << ". " << m_title << " by " << m_author << ", is available: " << available << endl;
}
