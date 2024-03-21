//
// Created by Max on 19.03.2024.
//

#ifndef OOP_LAB_1_7_ACCOUNT_H
#define OOP_LAB_1_7_ACCOUNT_H


#include <string>
#include "Money.h"

using namespace std;

class Account
{
private:
    static constexpr double dollar = 39.05;
    static constexpr double euro = 42.74;

    string surname;
    string iban;
    double percentage;
    Money money;

    static string digitToText(int digit);

    static string teenToText(int teen);

    static string tensToText(int tens);

    static string classToText(int num);

public:
    string getSurname() const;

    string getIban() const;

    double getPercentage() const;

    bool setPercentage(double percentage);

    Money getMoney() const;

    bool Init(const string &surname, const string &iban, double percentage, Money money);

    void Read();

    string toString() const;

    void Display() const;

    void changeOwner(string surname);

    bool withdrawCash(Money cash);

    void putCash(Money cash);

    void creditPercentage();

    Money toDollars() const;

    Money toEuros() const;

    string toTextString() const;
};


#endif //OOP_LAB_1_7_ACCOUNT_H
