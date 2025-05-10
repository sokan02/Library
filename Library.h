//
// Created by sofija on 10/05/25.
//

#ifndef LIBRARY_H
#define LIBRARY_H
#include "Shelf.h"
#include "MemberList.h"

class Library {
public:
    Library();
    ~Library();
    void run();
private:
    unsigned choice;
    Shelf* m_shelf;
    MemberList* m_memberList;
    void welcome();
};

#endif //LIBRARY_H
