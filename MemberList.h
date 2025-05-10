//
// Created by sofija on 10/05/25.
//

#ifndef MEMBERLIST_H
#define MEMBERLIST_H
#include <string>
#include <vector>
using namespace std;

class Member;

class MemberList {
public:
    MemberList(string filepath);
    ~MemberList();
    void addMember(string name);
    Member* getMember(unsigned id);
    void viewMembers();
private:
    vector<Member*> m_members;
    unsigned m_idLastMember;
};

#endif //MEMBERLIST_H
