#ifndef UNTITLED_FRACTION_H
#define UNTITLED_FRACTION_H

#include "bits/stdc++.h"
using namespace std;

class Fraction {
protected:
    int numerator,denominator;
public:
    Fraction();
    Fraction(int num,int den);
    Fraction operator+(const Fraction & f);
    Fraction operator-(const Fraction & obj);
    Fraction operator*(const Fraction & obj);
    Fraction operator/(const Fraction & obj);

    bool operator>(const Fraction& obj);
    bool operator>=(const Fraction& obj);
    bool operator<(const Fraction& obj);
    bool operator<=(const Fraction& obj);
    bool operator==(const Fraction& obj);
    int gcd(int n,int d);
    void reduce();

    friend ostream& operator<<(ostream& os, const Fraction& obj);
    friend istream& operator>>(istream& is, Fraction& obj);
};


#endif

