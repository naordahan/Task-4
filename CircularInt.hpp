#ifndef CIRCULAR_INT_CIRCULARINT_H
#define CIRCULAR_INT_CIRCULARINT_H

#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;


class CircularInt {
	public:
		int start, finish, current;
	bool check_input(int, int);




	CircularInt(int, int);
	CircularInt operator-=(int val);
	CircularInt & operator-();
	CircularInt & operator-(int start_point);
	CircularInt & operator-(CircularInt const & c);
	CircularInt & operator*=(int val);
	CircularInt & operator+(CircularInt other);
	CircularInt &CircularInt::operator+(int other);
	CircularInt operator/=(int val);
	CircularInt & operator/(int num);
	CircularInt & operator+=(int const & num);
	CircularInt & operator+=(CircularInt const & c);
	std::string to_string() { return std::to_string(current); }


	//operator overloading:


	/*friend std::ostream& operator<<(std::ostream& os, CircularInt& s) {
		os << std::to_string(s.get_current());
		return os;
	}
*/
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
	friend ostream &operator<<(ostream &output, const CircularInt &o);
	friend istream &operator>>(istream &input, CircularInt &o);

};
 


#endif
