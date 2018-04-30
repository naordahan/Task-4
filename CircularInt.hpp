
#pragma once
#include <iostream>
using namespace std;

class CircularInt
{
private:
  int minimal;
  int maximal;
  int current;
  int range;
  int Current(int value);

public:
  CircularInt(int low, int high);
  CircularInt();
  CircularInt(const CircularInt &other);

  CircularInt &operator=(int c);
  CircularInt &operator+=(int const &value);
  CircularInt &operator+=(CircularInt const &obj);
  CircularInt &operator++();
  CircularInt operator++(int);
  CircularInt &operator+(int const &value);
  CircularInt &operator+(CircularInt const &obj);
  CircularInt &operator-=(int const &value);
  CircularInt &operator-=(CircularInt const &obj);
  CircularInt &operator--();
  CircularInt operator--(int);
  CircularInt &operator-();
  CircularInt &operator-(int const &value);
  CircularInt &operator-(CircularInt const &obj);
  CircularInt &operator*(int const &value);
  CircularInt &operator*(CircularInt const &obj);
  CircularInt &operator*=(int const &value);
  CircularInt &operator*=(CircularInt const &obj);
  CircularInt &operator/(int const &value);
  CircularInt &operator/(CircularInt const &obj);
  CircularInt &operator/=(int const &value);
  CircularInt &operator/=(CircularInt const &obj);
  bool operator==(CircularInt const &c);
  friend bool operator==(int val, const CircularInt &c);
  bool operator!=(CircularInt const &c);
  friend bool operator!=(int val, const CircularInt &c);
  bool operator==(int const &c);
  bool operator!=(int const &c);
  bool operator>(CircularInt const &c);
  friend bool operator>(int val, const CircularInt &c);
  bool operator<(CircularInt const &c);
  bool operator>(int const &c);
  bool operator<(int const &c);
  friend bool operator<(int val, const CircularInt &c);
  bool operator>=(CircularInt const &c);
  bool operator<=(CircularInt const &c);
  bool operator>=(int const &c);
  friend bool operator>=(int val, const CircularInt &c);
  bool operator<=(int const &c);
  friend bool operator<=(int val, const CircularInt &c);
  friend CircularInt operator-(int val, const CircularInt &c);
  friend CircularInt operator+(int val, const CircularInt &c);
  friend CircularInt operator/(int val, const CircularInt &c);
  friend ostream &operator<<(ostream &output, const CircularInt &o);
  friend istream &operator>>(istream &input, CircularInt &o);
};
