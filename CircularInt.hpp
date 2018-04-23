
#ifndef CIRCULAR_INT_CIRCULARINT_H
#define CIRCULAR_INT_CIRCULARINT_H

#include <stdlib.h>
#include <string>
#include <iostream>


class CircularInt {
	int start, finish, current;
	bool check_input(int, int);



public:
	CircularInt(int, int);
	int get_start() { return start; }
	int get_finish() { return  finish; }
	int get_current() { return current; }
	int set_current(int val) { this->current = val; }
	std::string to_string() { return std::to_string(get_current()); }
	int get_range() { return get_finish() - get_start() + 1; }


	//operator overloading:


	friend std::ostream& operator<<(std::ostream& os, CircularInt& s) {
		os << std::to_string(s.get_current());
		return os;
	}



	CircularInt&operator+=(int num) {
		int total_n = (*this).get_current() + num;
		int mod_range = this->get_range();
		int ans = total_n % mod_range;
		this->set_current(ans);
		return (*this);

	}



	CircularInt operator++(int) { 
		this->operator+=(1);
		return *this;
	}

	CircularInt operator-=(int); //operator -=
	CircularInt& operator-(); //operator -
	CircularInt& operator-(int); 
	CircularInt&operator*=(int); 
	CircularInt&operator+(CircularInt); 
	CircularInt operator/=(int);
	CircularInt& operator/(int num);



};
CircularInt operator-(int num, CircularInt  &other); 


#endif
