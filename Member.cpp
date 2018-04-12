#include "Member.h"
using namespace std;


    Member::Member()
    {
        MemberNum++;
    }
    Member::~Member()
    {
        for(int i=0; i<following.size();i++)
        {
        this->unfollow(*following[i]);
        }
        for(int i=0; i<followers.size();i++)
        {
        followers[i]->unfollow(*this);
        
        }
        MemberNum--;
    }
void Member::follow(Member& f_name){
	Member *Point = &f_name; 
	if(this==Point)
		return;
	for(int i=0; i<following.size(); i++)
		if(following[i] == Point)
			return;
	
	following.push_back(Point);
	Point->followers.push_back(this);	
}
    
void Member::unfollow(Member& f_name){
	Member *Point = &f_name; 
	bool flag = false;
	for(int i=0; i<following.size(); i++){
		if(following[i] == Point){
			following.erase(following.begin() + i);
			flag = true;
		}
	}
	if(flag) return;
	
	for(int i=0; i< Point->followers.size(); i++){
		if(Point->followers[i] == this){
			Point->followers.erase(Point->followers.begin()+i);
			return;
		}
	}
	
}

    int Member::numFollowing()
    {
        return following.size();
    }

    int Member::numFollowers()
    {
        return followers.size();
    }

    int Member::count()
    {
        
        return MemberNum;
    }