//
// Created by Max on 19.03.2024.
//

#ifndef OOP_LAB_1_7_MONEY_H
#define OOP_LAB_1_7_MONEY_H


#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Money
{
private:
    long hryvnas;
    unsigned char kopiykas;

public:
    long getHryvnas() const;

    void setHryvnas(long hryvnas);

    unsigned char getKopiykas() const;

    void setKopiykas(unsigned char kopiykas);

    void Init(long hryvnas, unsigned char kopiykas);

    void Read();

    string toString() const;

    void Display() const;

    static Money add(Money money1, Money money2);

    static Money subtract(Money money1, Money money2);

    static double divide(Money money1, Money money2);

    static Money divide(Money money, double value);

    static Money multiply(Money money, double value);

    static bool isEqual(Money money1, Money money2);

    static bool isMore(Money money1, Money money2);

    static bool isLess(Money money1, Money money2);
};



#endif //OOP_LAB_1_7_MONEY_H
