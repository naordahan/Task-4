#include "CircularInt.hpp"
#include <string>
#include <iostream>
using namespace std;

CircularInt::CircularInt(int low, int high)
{
    maximal = max(high, low);
    minimal = min(low, high);
    current = minimal;
    range = abs(maximal - minimal) + 1;
}
CircularInt::CircularInt(const CircularInt &other)
{
    this->maximal = other.maximal;
    this->minimal = other.minimal;
    this->range = other.range;
    this->current = other.current;
}

int CircularInt::Current(int value)
{
    int current = ((value - minimal) % (range) + range) % (range) + minimal;
    return current;
}

CircularInt &CircularInt::operator=(int c)
{
    this->current = Current(c);
    return *this;
}

CircularInt &CircularInt::operator+=(int const &value)
{
    int res = current + value;
    current = Current(res);
    return *this;
}

CircularInt &CircularInt::operator+=(CircularInt const &value)
{
    int res = current + value.current;
    current = Current(res);
    return *this;
}

CircularInt &CircularInt::operator-=(int const &value)
{
    int res = current - value;
    current = Current(res);
    return *this;
}

CircularInt &CircularInt::operator-=(CircularInt const &value)
{
    int res = current - value.current;
    current = Current(res);
    return *this;
}

CircularInt &CircularInt::operator++()
{
    int res = ++current;
    current = Current(res);
    return *this;
}

CircularInt CircularInt::operator++(int)
{
    CircularInt temp(*this);
    ++(*this);
    return temp;
}

CircularInt CircularInt::operator--(int)
{
    CircularInt temp(*this);
    --(*this);
    return temp;
}

CircularInt &CircularInt::operator--()
{
    int res = current - 1;
    current = Current(res);
    return *this;
}

CircularInt &CircularInt::operator*=(int const &value)
{
    current = Current(current * value);
    return *this;
}

CircularInt &CircularInt::operator*=(CircularInt const &value)
{
    current = Current(current * value.current);
    return *this;
}

CircularInt &CircularInt::operator%=(int const &value)
{
    current = Current(current % value);
    return *this;
}

CircularInt &CircularInt::operator%=(CircularInt const &value)
{
    current = Current(current % value.current);
    return *this;
}

bool CircularInt::operator==(CircularInt const &c)
{
    return (this->maximal == c.maximal) && (this->minimal == c.minimal) && (this->current == c.current);
}

bool CircularInt::operator!=(CircularInt const &c)
{
    return this->minimal != c.minimal || this->maximal != c.maximal || this->current != c.current;
}

bool CircularInt::operator==(int const &c)
{
    return (this->current) == c;
}

bool CircularInt::operator!=(int const &c)
{
    return (this->current) != c;
}

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
bool operator==(int val, const CircularInt &c)
{
    return val == c.current;
}

bool operator!=(int val, const CircularInt &c)
{
    return val != c.current;
}

bool operator>(int val, const CircularInt &c)
{
    return val > c.current;
}

bool operator<(int val, const CircularInt &c)
{
    return val < c.current;
}

bool operator>=(int val, const CircularInt &c)
{
    return val >= c.current;
}

bool operator<=(int val, const CircularInt &c)
{
    return val <= c.current;
}

CircularInt operator-(int val, const CircularInt &c)
{
    CircularInt res(c);
    int result = val - c.current;
    res.current = res.Current(result);
    return res;
}

CircularInt operator+(int val, const CircularInt &c)
{
    CircularInt res(c);
    int result = c.current + val;
    res.current = res.Current(result);
    return res;
}

CircularInt operator/(int val, const CircularInt &c)
{
    CircularInt res(c);
    int result = val / c.current;
    res.current = res.Current(result);
    return res;
}
CircularInt &CircularInt::operator+(int const &value)
{
    CircularInt *temp = new CircularInt(*this);
    int res = current + value;
    temp->current = Current(res);
    return *temp;
}

CircularInt &CircularInt::operator+(CircularInt const &value)
{
    CircularInt *temp = new CircularInt(*this);
    int res = current + value.current;
    temp->current = Current(res);
    return *temp;
}

CircularInt &CircularInt::operator-()
{
    CircularInt *res = new CircularInt(*this);
    int result = current * -1;
    res->current = Current(result);
    return *res;
}

CircularInt &CircularInt::operator-(int const &value)
{
    CircularInt *temp = new CircularInt(*this);
    int res = current - value;
    temp->current = Current(res);
    return *temp;
}

CircularInt &CircularInt::operator-(CircularInt const &value)
{
    CircularInt *temp = new CircularInt(*this);
    int res = current - value.current;
    temp->current = Current(res);
    return *temp;
}
CircularInt &CircularInt::operator*(int const &value)
{
    CircularInt *temp = new CircularInt(*this);
    int res = current * value;
    temp->current = Current(res);
    return *temp;
}

CircularInt &CircularInt::operator*(CircularInt const &value)
{
    CircularInt *temp = new CircularInt(*this);
    int res = current * value.current;
    temp->current = Current(res);
    return *temp;
}

CircularInt &CircularInt::operator/(int const &value)
{
    CircularInt *temp = new CircularInt(*this);
    if (current % value != 0)
    {
        throw string(string("There is no number in range"));
    }
    int res = current / value;
    temp->current = Current(res);
    return *temp;
}

CircularInt &CircularInt::operator/(CircularInt const &value)
{
    if (current % value.current != 0)
    {
        throw string(string("There is no number in range"));
    }
    CircularInt *temp = new CircularInt(*this);
    int res = current / value.current;
    temp->current = Current(res);
    return *temp;
}


ostream &operator<<(ostream &output, const CircularInt &o)
{
    output << o.current;
    return output;
}
istream &operator>>(istream &input, CircularInt &o)
{
    int n;
    input >> n;
    o.current = o.Current(n);
    return input;
}
