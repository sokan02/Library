#include "Reader.h"
#include <iostream>
using namespace std;

Reader::Reader(istream* input) : m_input(input) {}

Reader::~Reader() {}

string Reader::getNextLine() {
	string line;
	getline(*m_input, line);
	return line;
}

bool Reader::endOfRead() {
	return m_input->eof();
}

FileReader::FileReader(string filepath) : Reader(new ifstream(filepath)) {}

FileReader::~FileReader() {
	((ifstream*) m_input)->close();
	delete m_input;
}

ConsoleReader::ConsoleReader() : Reader(&cin) {}

string ConsoleReader::getNextLine() {
	cin.get();
	return Reader::getNextLine();
}