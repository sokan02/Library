#ifndef MEMBER_H
#define MEMBER_H

#include<string>
using namespace std;

class Member
{
private:
    string name;
    unsigned  id;
public:
    Member(string name, unsigned id);

    void setId(unsigned id);
    unsigned getId();

    void setName(string name);
    string getName();

    void memberDisplay();
};



#endif