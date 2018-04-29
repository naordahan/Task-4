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
	if (val >= this->get_current()) {
		val = (val - this->get_current()) % this->get_range();
		ans = get_finish() - val;
	}
	else {
		ans = this->get_current() - val;

	}
	if (ans == 0) ans = get_finish();

	this->set_current(ans);
}

CircularInt& CircularInt::operator-() {  
	int ans = this->get_finish() - this->get_current();
	this->set_current(ans);
	return *this;

}

CircularInt& CircularInt::operator-(int start_point) { 
	int old_current = this->get_current();
	this->set_current(start_point);
	*this -= old_current;
	return *this;
}


CircularInt &CircularInt::operator*=(int val) { 


	int tmp = val * this->get_current();
	(*this) += (tmp);
	(*this)++;
	return *this;
}

CircularInt &CircularInt::operator+(CircularInt other) { 
	(*this).operator+=(other.get_current());
	return (*this);
}

CircularInt CircularInt::operator/=(int val) {
	CircularInt result(*this);
	int total = this->get_current() * val;
	result -= total;
	return result;
}

CircularInt& CircularInt::operator/(int num) {
	int total = num * this->get_current();
	*this -= total;
	return (*this);
}

CircularInt operator-(int num, CircularInt  &other) { 
	int ans;
	CircularInt result{ other.get_start(), other.get_finish() };
	result.set_current(num);

	result -= other.get_current();
	return result;

}
// operator << 
  ostream& operator<<(ostream& os, const CircularInt& c)
{  
    os << c.get_current;  
    return os;  
} 

// operator >>
  istream& operator>>(istream& is,  CircularInt& c)
{  
    is >> c.get_current;  
    return is;  
} 
//logic operators
bool CircularInt::operator>(CircularInt const &c)
{
	return this->current > c.get_current;
}

bool CircularInt::operator<(CircularInt const &c)
{
	return this->current < c.get_current;
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
bool operator==(int num, const CircularInt &c)
{
	return num == c.get_current;
}

bool operator!=(int num, const CircularInt &c)
{
	return num != c.get_current;
}

bool operator>(int num, const CircularInt &c)
{
	return num > c.get_current;
}

bool operator<(int num, const CircularInt &c)
{
	return num < c.get_current;
}

bool operator>=(int num, const CircularInt &c)
{
	return num >= c.get_current;
}

bool operator<=(int num, const CircularInt &c)
{
	return num <= c.get_current;
}

// operator == with another object
bool CircularInt::operator==(CircularInt const &c)
{
    return (this->finish == c.get_finish) && (this->start == c.get_start) && (this->current == c.get_current);
}

//operator == with another number
bool CircularInt::operator==(int const &c)
{
    return (this->current) == c;
}

//operator != with another object
bool CircularInt::operator!=(CircularInt const &c)
{
    return this->finish != c.get_finish || this->start != c.get_start || this->current != c.get_current;
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
    while(current>finish){
	    current-=finish;
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
    while(current<start){
	    current+=finish;
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


