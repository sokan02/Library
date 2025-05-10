#include "Member.h"

#include <iostream>
#include <bits/ostream.tcc>

Member::Member(string name, unsigned id) : name(name), id(id) {}

unsigned Member::getId()
{
    return this->id;
}

void Member::setId(unsigned id)
{
    this->id = id;
}

string Member::getName()
{
    return this->name;
}

void Member::setName(string name)
{
    this->name = name;
}

void Member::memberDisplay() {
    cout << this->name << " " << this->id << endl;
}