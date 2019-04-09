//
// Created by Alex Hughes on 2019-04-05.
//
/*Alex Hughes
CS 110B
4/5/19
Professor Dave
Assignment 11.1

Assignment calls for making refinements to the class that I wrote last week. Added a private "simplify()" function to my
class and called it from the appropriate member functions. Modified my overloaded << operator so that improper Fractions
are printed as mixed numbers. The Fraction class has multiple member functions for operator interactions between Frac
objects.

Pre/Post:


Fractions();
    post: constructs a fraction object with a numerator of zero and a denominator of 1.

Fraction(int whole)
    pre: A whole number to construct a fraction object.

Fraction(int num, int den)
    pre: Integers num and den to start the numerator and denominator of a fraction object


friend fraction operator+(const fraction& left, const fraction& right)
    pre: constant fraction object to the left of the operator and constant fraction object to the right of the operator.
    post: The left and right fractions are added and returned.

friend fraction operator-(const fraction& left, const fraction& right)
    pre:  constant fraction object to the left of the operator and constant fraction object to the right of the operator.
    post: The left and right fractions are subtracted and returned.

friend fraction operator*(const fraction& left, const fraction& right)
    pre: A constant fraction object to the left of the operator and a constant fraction object to the right of the operator.
    post: The left and right fractions are multiplied and returned.

friend fraction operator/(const fraction& left, const fraction& right)
    pre: A constant fraction object to the left of the operator and a constant fraction object to the right of the operator.
    post: The left and right fractions are divided and returned.

friend ostream& operator<<(ostream& out, const fraction &f)
    post: outputs f in reduced form.

friend istream& operator>>(istream& in, fraction &f)
    post: takes from user input to set values of f.

friend bool operator<(const fraction& left, const fraction& right)
    pre: A constant fraction object to the left of the operator and a constant fraction object to the right of the
        operator.
    post: Returns true if the left fraction is less than the right.

friend bool operator<=(const fraction& left, const fraction& right)
    pre: A constant fraction object to the left of the operator and a constant fraction object to the right of the
        operator.
    post: Returns true if the left fraction is less than or equal to the right.

friend bool operator>=(const fraction& left, const fraction& right)
    pre: A constant fraction object to the left of the operator and a constant fraction object to the right of the
        operator.
    post: Returns true if the left fraction is greater than or equal to the right.

friend bool operator>(const fraction& left, const fraction& right)
    pre: A constant fraction object to the left of the operator and a constant fraction object to the right of the
        operator.
    post: Returns true if the left fraction is greater than the right.

friend bool operator==(const fraction& left, const fraction& right)
    pre: A constant fraction object to the left of the operator and a constant fraction object to the right of the
        operator.
    post: Returns true if the left fraction is equal to the right.

friend bool operator!=(const fraction& left, const fraction& right)
    pre: A constant fraction object to the left of the operator and a constant fraction object to the right of the
        operator.
    post: Returns true if the left fraction is not equal to the right.

fraction operator+=(const fraction& right)
    pre: A constant fraction on the right of the operator.
    post: The calling fraction and right fraction are added and returned.

fraction operator-=(const fraction& right)
    pre: A constant fraction on the right of the operator.
    post: The calling fraction and right fraction are subtracted and returned.

fraction operator*=(const fraction& right)
    pre: A constant fraction on the right of the operator.
    post: The calling fraction and right fraction are multiplied and returned.

fraction operator/=(const fraction& right)
    pre: A constant fraction on the right of the operator.
    post: The calling fraction and right fraction are divided and returned.

fraction operator++()
    post: The fraction is increased by 1.

fraction operator++(int)
    post: The fraction is increased by 1.

fraction operator--()
    post: The fraction is decreased by 1.

fraction operator--(int)
    post: The fraction is decreased by 1.

*/


#ifndef A11_1_FRACTION_H
#define A11_1_FRACTION_H

#include <iostream>
using namespace std;
namespace cs_fraction
{
    class Fraction
    {
    public:
        Fraction();

        Fraction(int wholeNumber);

        Fraction(int num, int den);


        friend Fraction operator+(const Fraction& left,
                                  const Fraction& right);

        friend Fraction operator-(const Fraction& left,
                                  const Fraction& right);

        friend Fraction operator*(const Fraction& left,
                                  const Fraction& right);

        friend Fraction operator/(const Fraction& left,
                                  const Fraction& right);

        friend ostream& operator<<(ostream& out,
                                   const Fraction &f);

        friend istream& operator>>(istream& in,
                                   Fraction &f);

        friend bool operator<(const Fraction& left,
                              const Fraction& right);

        friend bool operator<=(const Fraction& left,
                               const Fraction& right);

        friend bool operator>=(const Fraction& left,
                               const Fraction& right);

        friend bool operator>(const Fraction& left,
                              const Fraction& right);

        friend bool operator==(const Fraction& left,
                               const Fraction& right);

        friend bool operator!=(const Fraction& left,
                               const Fraction& right);

        Fraction operator+=(const Fraction& right);

        Fraction operator-=(const Fraction& right);

        Fraction operator*=(const Fraction& right);

        Fraction operator/=(const Fraction& right);

        Fraction operator++();

        Fraction operator++(int);

        Fraction operator--();

        Fraction operator--(int);


    private:
        void simplify();
        int numValue;
        int denomValue;
    };
}



#endif //A11_1_FRACTION_H



/* Output:
Assertion failed: (in), function BasicTest, file /Users/alexhughes/CLionProjects/a11_1/client.cpp, line 49.

----- Testing basic Fraction creation & printing
(Fractions should be in reduced form, and as mixed numbers.)
Fraction [0] = 1/2
Fraction [1] = -5/7
Fraction [2] = 10
Fraction [3] = -4
Fraction [4] = 0
Fraction [5] = 4+2/3
Fraction [6] = 0

----- Now reading Fractions from Fraction.txt

Process finished with exit code 6


*/
