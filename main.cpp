#include "Book.h"
#include "Member.h"
#include "Library.h"
#include "Parser.h"
#include "Reader.h"
#include<vector>
#include "Shelf.h"
#include<iostream>

#include "MemberList.h"
using namespace std;
int main() {
    Library *library = new Library();
    library->run();
    delete library;
    return 0;
}