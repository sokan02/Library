//
// Created by sofija on 09/05/25.
//
#include<vector>
#include "Parser.h"
#include<string>
using namespace std;

Parser::Parser(Reader* reader) : m_reader(reader) {}

Parser::~Parser() {
    delete m_reader;
}

Book* Parser::getNextBook() {
    string line = m_reader->getNextLine();
    if(m_reader->endOfRead()) return nullptr;
    return parseBook(line);
}

Member* Parser::getNextMember() {
    string line = m_reader->getNextLine();
    if(m_reader->endOfRead()) return nullptr;
    return parseMember(line);
}

ParserA::ParserA(Reader* reader) : Parser(reader) {}

Book* ParserA::parseBook(string line) {
    vector<string> fields;
    bool inQuotes = false;
    string field;

    for(char c : line) {
        if(c == '"') inQuotes = !inQuotes;
        else if(c == ',' && !inQuotes) {
            fields.push_back(field);
            field.clear();
        }
        else field += c;
    }
    fields.push_back(field);

    if(fields.size() != 6) return nullptr;
    bool available = (fields[5] == "true");
    return new Book(fields[0], fields[1], stoi(fields[2]),stoi(fields[3]),fields[4],available);
}

Member* ParserA::parseMember(string line) {
    return nullptr;
}

ParserB::ParserB(Reader* reader) : Parser(reader) {}

Book* ParserB::parseBook(string line) {
    return nullptr;
}

Member* ParserB::parseMember(string line) {
    vector<string> fields;
    bool inQuotes = false;
    string field;

    for(char c : line) {
        if(c == '"') inQuotes = !inQuotes;
        else if(c == ',' && !inQuotes) {
            fields.push_back(field);
            field.clear();
        }
        else field += c;
    }
    fields.push_back(field);

    if(fields.size() != 2) return nullptr;
    return new Member(fields[0], stoi(fields[1]));
}