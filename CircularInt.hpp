#ifndef CIRCULAR_INT_CIRCULARINT_H
#define CIRCULAR_INT_CIRCULARINT_H

#include <stdlib.h>
#include <string>
#include <iostream>


class CircularInt {
	public:
		int start, finish, current;
	bool check_input(int, int);




	CircularInt(int, int);
	CircularInt operator-=(int val);
	CircularInt & operator-();
	CircularInt & operator-(int start_point);
	CircularInt & operator-(CircularInt const & c);
	std::string to_string() { return std::to_string(current); }


	//operator overloading:


	friend std::ostream& operator<<(std::ostream& os, CircularInt& s) {
		os << std::to_string(s.current);
		return os;
	}

	//assuming the range of the two hours is the same
	//arithmetic operators
	CircularInt& operator++ (); //prefix ++ operator
	CircularInt operator-- (int hour1); //Postfix -- operator
	CircularInt& operator--(); //prefix -- operator
	CircularInt &operator+=(int const num);
	CircularInt &CircularInt::operator+=(int const &num)
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
 


#endif
