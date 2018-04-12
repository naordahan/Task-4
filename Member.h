#ifndef MEMBER_H
#define MEMBER_H
#include <iostream>
#include <algorithm>
#include <vector>
#include<string>

 class Member
{
    int user_id;  // in case you have 2 users with the same first and last name
    static int MemberNum;

    public:
    std::vector<Member*> following;
    std::vector<Member*> followers;
    std::string first;
    std::string last;

   
    Member();
    ~Member();
    void follow (Member &f_name);    
    void unfollow(Member &f_name);
    int numFollowing();
    int numFollowers();
    static int count();
};
#endif