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
	CircularInt operator-=(int val);
	CircularInt & operator-();
	CircularInt & operator-(int start_point);
	CircularInt & operator-(CircularInt const & c);
	int static inline get_start() { return start; }
	int static inline get_finish() { return  finish; }
	int static inline get_current() { return current; }
	int static set_current(int val) { this->current = val; }
	std::string to_string() { return std::to_string(get_current()); }
	int static inline get_range() { return get_finish() - get_start() + 1; }


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
	//assuming the range of the two hours is the same
	//arithmetic operators
	CircularInt& operator++ (); //prefix ++ operator
	CircularInt operator-- (int hour1); //Postfix -- operator
	CircularInt& operator--(); //prefix -- operator

	CircularInt & operator*=(int val);
	CircularInt & operator+(CircularInt other);
	CircularInt operator/=(int);
	CircularInt& operator/(int num);
	//logic operators between 2 objects
	 bool operator<(CircularInt const &c);
	 bool operator>(CircularInt const &c);
	 bool operator>(int const &c);
	 bool operator<(int const &c);
	 bool operator==(CircularInt  &c);
	 bool operator==(int const & c);
	 bool operator<=(CircularInt const &c);
	 bool operator>=(int const & c);
	 bool operator<=(int const & c);
	 bool operator>=(CircularInt const &c);
	 bool operator!=(CircularInt  &c);
	 bool operator!=(int const & c);

};
 


#end
