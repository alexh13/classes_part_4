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
are printed as mixed numbers.


*/


#ifndef A11_1_FRACTION_H
#define A11_1_FRACTION_H



#include <cassert>

class Fraction
{
private:
    int numerator, denominator;

    void simplify();

public:

    Fraction();
    // Default constructor



    Fraction(int a,int b);
    // Constructor with two parameters


    Fraction addedTo(Fraction f2) const;
    //post: The sum of the calling object is returned



    Fraction subtract(Fraction f2) const;
    //Post: The subtraction of the calling object is returned



    Fraction multipliedBy(Fraction f2) const;
    //Post: The multiplied calling object is returned


    Fraction dividedBy(Fraction& f2) const;
    //Post: The divided calling object is returned



    int get_num() const;
    //Post: returns numerator



    int get_den() const;
    //Post: returns denominator



    bool isEqualTo(Fraction f2);
    //Post: returns true is called object is equal, otherwise false



    void print() const;
    //Post: Output called object in a numerator/denominator style


};


#endif //A11_1_FRACTION_H
