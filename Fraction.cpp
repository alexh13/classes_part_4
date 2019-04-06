#include <iostream>
#include <cassert>
#include "fraction.h"

using namespace std;






Fraction::Fraction()
{
    numerator = 0;
    denominator = 1;
}






Fraction::Fraction(int a, int b)
{
    numerator = a;
    assert(b != 0);
    denominator = b;
    simplify();
}






Fraction Fraction::addedTo(Fraction f2) const
{
    int new_num = numerator*f2.get_den() + denominator*f2.get_num();
    int new_den = denominator*f2.get_den();
    return {new_num, new_den};
}






Fraction Fraction::subtract(Fraction f2) const
{
    int new_num = numerator*f2.get_den() - denominator*f2.get_num();
    int new_den = denominator*f2.get_den();
    return {new_num,new_den};
}






Fraction Fraction::multipliedBy(Fraction f2) const
{
    int new_num = numerator*f2.get_num();
    int new_den = denominator*f2.get_den();
    return {new_num,new_den};
}







Fraction Fraction::dividedBy(Fraction& f2) const
{
    int new_num = numerator * f2.get_den();
    int new_den = denominator * f2.get_num();
    Fraction temp(new_num,new_den);
    return temp;
}






bool Fraction::isEqualTo(Fraction f2)
{
    return (numerator==f2.get_num() && denominator == f2.get_den());
}






void Fraction::print() const
{
    cout << numerator << "/" << denominator;
}






int Fraction::get_num() const
{
    return numerator;
}






int Fraction::get_den() const
{
    return denominator;
}






void Fraction::simplify()
{
    int a = numerator;
    int b = denominator;
    while (a != b) {
        if (a > b) {
            a -= b;
        }else {
            b -= a;
        }
    }
    numerator = numerator/a;
    denominator = denominator/a;
}