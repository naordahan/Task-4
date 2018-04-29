#include <iostream>
#include "CircularInt.hpp"
bool CircularInt::check_input(int a, int b) {
	int a_abs = abs(a);
	int b_abs = abs(b);
	return b_abs - a_abs;

}

CircularInt::CircularInt(int lower, int upper) {

	if (CircularInt::check_input(lower, upper) > 0) {
		this->start = lower;
		this->finish = upper;
		this->current = lower;
	}
	else {
		throw "The lower bound should be smaller then the upper bound!";
	}

}

CircularInt CircularInt::operator-=(int val) {
	int ans;
	if (val >= this->current) {
		val = (val - this->current) % (this->finish - this->start + 1);
		ans = this->finish - val;
	}
	else {
		ans = this->current - val;

	}
	if (ans == 0) ans = finish;

	this->current = ans;
}

CircularInt& CircularInt::operator-() {
	int ans = this->finish - this->current;
	this->current = ans;
	return *this;

}

CircularInt& CircularInt::operator-(int start_point) {
	int old_current = this->current;
	this->current = start_point;
	*this -= old_current;
	return *this;
}

CircularInt &CircularInt::operator-(CircularInt const &c)
{
	CircularInt *temp = new CircularInt(*this);
	int result = current - c.current;
	while (result<c.start)
		temp->current = result + c.finish;
	return *temp;
}

// operator - substracts an object from a number
CircularInt operator-(int num, CircularInt  &other) {
	CircularInt result{ other.start, other.finish };
	result.current = num;

	result.current = ((result.current - other.current));
	while (result.current<other.start)
		result.current = ((result.current + other.finish));
	return result;
}
// operator - substracts a number from an object
CircularInt operator-(CircularInt  &other, int num) {
	CircularInt result{ other.start, other.finish };
	result.current = num;
	result.current = ((other.current - result.current));
	while (result.current<other.start)
		result.current = ((result.current + other.finish));
	return result;
}

CircularInt &CircularInt::operator*=(int val) {


	int tmp = val * this->current;
	(*this) += (tmp);
	//(*this)++;
	return *this;
}

CircularInt &CircularInt::operator+(CircularInt other) {
	(*this).operator+=(other.current);
	return (*this);
}
CircularInt &CircularInt::operator+(int other)
{
	this->current = (this->current+  other)% (this->finish - this->start + 1);
	return *this;
}


CircularInt CircularInt::operator/=(int val) {
	CircularInt result(*this);
	int total = this->current * val;
	result.current -= total;
	return result;
}

CircularInt& CircularInt::operator/(int num) {
	int total = num * this->current;
	this->current -= total;
	return (*this);
}


CircularInt &CircularInt::operator+=(int const &num)
{
	int res = current + num;
	this->current = res % (this->finish - this->start + 1);
	return *this;
}

CircularInt &CircularInt::operator+=(CircularInt const &c)
{
	int res = current + c.current;
	current = res % (this->finish - this->start + 1);
	return *this;
}

// operator << 
 std::ostream &operator<<( std::ostream &os, const CircularInt& c)
{
os << c. current;
return os;
}

// operator >>
 std::istream &operator>>( std::istream &is, CircularInt& c)
{
is >> c. current;
return is;
}
//logic operators
bool CircularInt::operator>(CircularInt const &c)
{
	return this->current > c.current;
}

bool CircularInt::operator<(CircularInt const &c)
{
	return this->current < c.current;
}

bool CircularInt::operator>(int const &c)
{
	return this->current > c;
}

bool CircularInt::operator<(int const &c)
{
	return this->current < c;
}

bool CircularInt::operator>=(CircularInt const &c)
{
	return this->current >= c.current;
}

bool CircularInt::operator<=(CircularInt const &c)
{
	return this->current <= c.current;
}

bool CircularInt::operator>=(int const &c)
{
	return this->current >= c;
}

bool CircularInt::operator<=(int const &c)
{
	return this->current <= c;
}
bool operator>(int num, const CircularInt &c)
{
	return num > c.current;
}

bool operator<(int num, const CircularInt &c)
{
	return num < c.current;
}

bool operator>=(int num, const CircularInt &c)
{
	return num >= c.current;
}

bool operator<=(int num, const CircularInt &c)
{
	return num <= c.current;
}

// operator == with another object
bool CircularInt::operator==(CircularInt  &c)
{
	return (this->finish == c.finish) && (this->start == c.start) && (this->current == c.current);
}

//operator == with another number
bool CircularInt::operator==(int const &c)
{
	return (this->current) == c;
}

//operator != with another object
bool CircularInt::operator!=(CircularInt  &c)
{
	return this->finish != c.finish || this->start != c.start || this->current != c.current;
}

//opertor != with another number 
bool CircularInt::operator!=(int const &c)
{
	return (this->current) != c;
}

//operator ++
CircularInt &CircularInt::operator++()
{
	int result = ++current;
	while (current>finish) {
		current -= finish;
	}
	return *this;
}

//operator++ adding a number to the object
CircularInt CircularInt::operator++(int)
{
	CircularInt tmp(*this);
	++(*this);
	return tmp;
}

//operator--
CircularInt &CircularInt::operator--()
{
	int result = current - 1;
	while (current<start) {
		current += finish;
	}
	return *this;
}

//operator-- 
CircularInt CircularInt::operator--(int)
{
	CircularInt tmp(*this);
	--(*this);
	return tmp;
}
