#include "Fraction.h"

Fraction::Fraction()
{
    numerator=1; denominator=1;
}

Fraction::Fraction(int num,int den)
{
    numerator=num;
    denominator=den;
}

int Fraction:: gcd(int n,int d)
{
    if(d==0)
        return n;
    return gcd(d,n%d);
}

void Fraction::reduce()
{
    int x;
    x= gcd(numerator,denominator);
    numerator/=x;
    denominator/=x;
}

Fraction Fraction::  operator+(const Fraction & f)
{
     Fraction obj;
     obj.denominator = denominator* f.denominator;
     obj.numerator = denominator*f.numerator + numerator*f.denominator;
     obj.reduce();
     return obj;
}

Fraction Fraction:: operator-(const Fraction & f)
{
    Fraction obj;
    obj.denominator = denominator* f.denominator;
    obj.numerator = numerator*f.denominator - denominator*f.numerator;
    obj.reduce();
    return obj;
}

Fraction Fraction:: operator*(const Fraction & f)
{
    Fraction obj;
    obj.denominator = denominator* f.denominator;
    obj.numerator = numerator*f.numerator ;
    obj.reduce();
    return obj;
}

Fraction Fraction:: operator/(const Fraction & f)
{
    Fraction obj;
    obj.denominator = denominator* f.numerator;
    obj.numerator = numerator*f.denominator ;
    obj.reduce();
    return obj;
}

bool Fraction:: operator>(const Fraction& obj)
{
    bool greater;
    if (numerator > obj.numerator || (numerator ==obj.numerator && denominator<obj.denominator))
        greater = true;
    else
        greater= false;
    return greater;
}

bool Fraction:: operator>=(const Fraction& obj)
{
    bool greaterOrEqual;
    if (numerator > obj.numerator || (numerator ==obj.numerator && denominator<obj.denominator)
        ||  (numerator == obj.numerator && denominator<obj.denominator))
        greaterOrEqual = true;
    else
        greaterOrEqual= false;
    return greaterOrEqual;
}

bool Fraction:: operator<(const Fraction& obj)
{
    bool less;
    if (numerator < obj.numerator || (numerator ==obj.numerator && denominator>obj.denominator))
        less = true;
    else
        less= false;
    return less;
}

bool Fraction:: operator<=(const Fraction& obj)
{
    bool lesserOrEqual;
    if (numerator < obj.numerator || (numerator ==obj.numerator && denominator>obj.denominator)
        || (numerator == obj.numerator && denominator<obj.denominator))
        lesserOrEqual = true;
    else
        lesserOrEqual= false;

    return lesserOrEqual;
}

bool Fraction:: operator==(const Fraction& obj)
{
    bool equal;
    if (numerator == obj.numerator && denominator<obj.denominator)
        equal = true;
    else
        equal= false;
    return equal;
}


ostream& operator<<(ostream& os, const Fraction& obj)
{
    if(obj.denominator==1)
         os<<obj.numerator<<endl;
    else if(obj.denominator==0)
         os << "denominator can not be zero\n";
    else
        os<<obj.numerator<<"/"<<obj.denominator<<endl;
    return os;
}

istream& operator>>(istream& is, Fraction& obj)
{
    cout<<"enter nominator: ";
    is>>obj.numerator;
    cout<<"enter denominator: ";
    is>> obj.denominator;


}
