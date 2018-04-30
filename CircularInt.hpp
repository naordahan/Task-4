#ifndef CIRCULAR_INT_CIRCULARINT_H
#define CIRCULAR_INT_CIRCULARINT_H

#include <stdlib.h>
#include <string>
#include <iostream>


class CircularInt {
	public:
		int start, finish, current;
	/*bool check_input(int a, int b);*/




	CircularInt(int, int);
	CircularInt operator-=(int val);
	CircularInt & operator-();
	CircularInt & operator-(int start_point);
	CircularInt & operator-(CircularInt const & c);
	CircularInt & operator*=(int val);
	CircularInt & operator+(CircularInt other);
	CircularInt & operator+(int other);
	CircularInt operator/=(int val);
	CircularInt & operator/(int num);
	CircularInt & operator+=(int const & num);
	CircularInt & operator+=(CircularInt const & c);
	std::string to_string() { return std::to_string(current); 
	 CircularInt & operator+ ( int const num);


	//operator overloading:

	//assuming the range of the two hours is the same
	//arithmetic operators

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
	 CircularInt & operator++();
	 CircularInt operator++(int);
	 CircularInt & operator--();
	 CircularInt operator--(int);

};
	CircularInt operator-(int num, CircularInt  &other);
	CircularInt operator-(CircularInt  &other, int num);


#endif
