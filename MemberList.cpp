//
// Created by sofija on 10/05/25.
//
#include "MemberList.h"
#include "Member.h"
#include "Parser.h"
using namespace std;

MemberList::MemberList(string filepath) {
    Member* member;
    m_idLastMember = 1;
    Parser* parser = new ParserB(new FileReader(filepath));
    while ((member = parser->getNextMember()) != nullptr) {
        m_members.push_back(member);
        m_idLastMember++;
    }
    delete parser;
}

MemberList::~MemberList() {
    for(Member* member : m_members) {
        delete member;
    }
}

void MemberList::viewMembers() {
    for(Member* member : m_members) {
        member->memberDisplay();
    }
}

Member* MemberList::getMember(unsigned id) {
    for(Member* member : m_members) {
        if(member->getId() == id) {
            return member;
        }
    }
    return nullptr;
}

void MemberList::addMember(string name) {
    m_members.push_back(new Member(name, m_idLastMember));
    ofstream membersFile("/home/sofija/Desktop/Library/memberList.txt", std::ios_base::app);
    membersFile << "" << name << "," << m_idLastMember++ << "\n";
    membersFile.close();
}