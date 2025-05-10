#ifndef READER_H
#define READER_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Reader {
public:

	Reader(istream* input);
	virtual ~Reader();

	virtual string getNextLine();

	virtual bool endOfRead();

protected:
	istream* m_input;
};

class ConsoleReader : public Reader {
public:

	ConsoleReader();

	virtual string getNextLine();
};

class FileReader : public Reader {
public:

	FileReader(string filepath);
	~FileReader();
};

#endif