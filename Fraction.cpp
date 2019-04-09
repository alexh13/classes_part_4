#include "Fraction.h"
#include <iostream>
#include <cassert>

using namespace std;
namespace cs_fraction
{
    Fraction::Fraction()
    {
        numValue = 0;
        denomValue = 1;
    }






    Fraction::Fraction(int wholeNumber)
    {
        numValue = wholeNumber;
        denomValue = 1;
    }






    Fraction::Fraction(int num, int den)
    {
        assert(den != 0);
        numValue = num;
        denomValue = den;
        simplify();
    }






    Fraction operator+(const Fraction& left, const Fraction& right)
    {
        int modNum1;
        int modNum2;
        int modDen;

        modDen = left.denomValue * right.denomValue;
        modNum1 = left.numValue * right.denomValue;
        modNum2 = right.numValue * left.denomValue;

        Fraction result = Fraction(modNum1 + modNum2, modDen);
        result.simplify();
        return result;
    }






    Fraction operator-(const Fraction& left, const Fraction& right)
    {
        int modNum1;
        int modNum2;
        int modDen;

        modDen = left.denomValue * right.denomValue;
        modNum1 = left.numValue * right.denomValue;
        modNum2 = right.numValue * left.denomValue;

        Fraction result = Fraction(modNum1 - modNum2, modDen);
        result.simplify();
        return result;
    }






    Fraction operator*(const Fraction& left, const Fraction& right)
    {
        Fraction result = Fraction(left.numValue * right.numValue, left.denomValue * right.denomValue);
        result.simplify();
        return result;
    }






    Fraction operator/(const Fraction& left, const Fraction& right)
    {
        Fraction result = Fraction(left.numValue * right.denomValue, left.denomValue * right.numValue);
        result.simplify();
        return result;
    }






    ostream& operator<<(ostream& out, const Fraction &f)
    {
        if(abs(f.numValue) > f.denomValue)
        {
            out << ((f.numValue - f.numValue % f.denomValue) / f.denomValue);

            if(f.numValue % f.denomValue != 0)
            {
                out << "+" << abs(f.numValue % f.denomValue) << "/" << f.denomValue;
            }
        }
        else if(f.numValue == f.denomValue)
        {
            out << f.numValue;
        }
        else if(f.numValue == 0)
        {
            out << 0;
        }
        else
        {
            out << f.numValue << "/" << f.denomValue;
        }

        return out;
    }






    istream& operator>>(istream& in, Fraction &f)
    {
        int temp;
        in >> temp;
        if (in.peek() == '+')
        {
            in.ignore();
            in >> f.numValue;
            in.ignore();
            in >> f.denomValue;
            if(temp < 0)
            {
                temp *= -1;
                f.numValue += temp * f.denomValue;
                f.numValue *= -1;
            }
            else
            {
                f.numValue += temp * f.denomValue;
            }
        }
        else if (in.peek() == '/')
        {
            in.ignore();
            in >> f.denomValue;
            f.numValue = temp;
        }
        else
        {
            f.numValue = temp;
            f.denomValue = 1;
        }

        f.simplify();
        return in;
    }






    bool operator<(const Fraction& left, const Fraction& right)
    {
        if(left.numValue * right.denomValue < right.numValue * left.denomValue)
            return true;
        else
            return false;
    }






    bool operator<=(const Fraction& left, const Fraction& right)
    {
        if(left.numValue * right.denomValue <= right.numValue * left.denomValue)
            return true;
        else
            return false;
    }






    bool operator>(const Fraction& left, const Fraction& right)
    {
        if(left.numValue * right.denomValue > right.numValue * left.denomValue)
            return true;
        else
            return false;
    }






    bool operator>=(const Fraction& left, const Fraction& right)
    {
        if(left.numValue * right.denomValue >= right.numValue * left.denomValue)
            return true;
        else
            return false;
    }






    bool operator==(const Fraction& left, const Fraction& right)
    {
        if(left.numValue * right.denomValue == right.numValue * left.denomValue)
            return true;
        else
            return false;
    }






    bool operator!=(const Fraction& left, const Fraction& right)
    {
        if(left.numValue * right.denomValue != right.numValue * left.denomValue)
            return true;
        else
            return false;
    }






    Fraction Fraction::operator+=(const Fraction& right)
    {
        *this = *this + right;

        return *this;
    }






    Fraction Fraction::operator-=(const Fraction& right)
    {
        *this = *this - right;

        return *this;
    }






    Fraction Fraction::operator*=(const Fraction& right)
    {
        *this = *this * right;

        return *this;
    }






    Fraction Fraction::operator/=(const Fraction& right)
    {
        *this = *this / right;

        return *this;
    }






    Fraction Fraction::operator++()
    {
        numValue += denomValue;
        return *this;
    }






    Fraction Fraction::operator++(int)
    {
        Fraction temp(numValue, denomValue);
        numValue += denomValue;
        return temp;
    }






    Fraction Fraction::operator--()
    {
        numValue -= denomValue;
        return *this;
    }






    Fraction Fraction::operator--(int)
    {
        Fraction temp(numValue, denomValue);
        numValue -= denomValue;
        return temp;
    }







// simplify the Fraction.
    void Fraction::simplify()
    {
        for (int i = denomValue; i > 1; i--)
        {

            if ((numValue % i == 0) && (denomValue % i == 0)) {

                numValue = numValue / i;
                denomValue = denomValue / i;
            }
        }
        if(denomValue < 0)
        {
            denomValue *= -1;
            numValue *= -1;
        }
    }
}

