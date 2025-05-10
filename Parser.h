//
// Created by sofija on 09/05/25.
//

#ifndef PARSER_H
#define PARSER_H

#include "Reader.h"
#include "Book.h"
#include "Member.h"

class Parser {
public:
    Parser(Reader* reader);

    virtual ~Parser();

    Book* getNextBook();
    Member* getNextMember();
protected:

    virtual Book* parseBook(string line) = 0;
    virtual Member* parseMember(string line) = 0;

    Reader* m_reader;

};

class ParserA : public Parser{
public:
    ParserA(Reader* reader);

protected:
    virtual Book* parseBook(string line);
    virtual Member* parseMember(string line);

};

class ParserB : public Parser{
public:
    ParserB(Reader* reader);
protected:
    virtual Member* parseMember(string line);
    virtual Book* parseBook(string line);
};

#endif //PARSER_H
