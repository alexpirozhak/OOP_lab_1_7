//
// Created by Max on 19.03.2024.
//

#include "Money.h"

long Money::getHryvnas() const
{
    return hryvnas;
}

void Money::setHryvnas(long hryvnas)
{
    this->hryvnas = hryvnas;
}

unsigned char Money::getKopiykas() const
{
    return kopiykas;
}

void Money::setKopiykas(unsigned char kopiykas)
{
    this->kopiykas = kopiykas;

    while (this->kopiykas >= 100)
    {
        hryvnas++;
        this->kopiykas -= 100;
    }
}

void Money::Init(long hryvnas, unsigned char kopiykas)
{
    setHryvnas(hryvnas);
    setKopiykas(kopiykas);
}

void Money::Read()
{
    cout << "Enter hryvnas: ";
    cin >> this->hryvnas;

    int kopiykas;
    cout << "Enter kopiykas: ";
    cin >> kopiykas;
    setKopiykas(static_cast<unsigned char>(kopiykas));
}

string Money::toString() const
{
    stringstream sout;
    sout << hryvnas << ',' << setw(2) << setfill('0')
         << static_cast<int>(kopiykas);
    return sout.str();
}

void Money::Display() const
{
    cout << toString() << endl;
}

Money Money::add(Money money1, Money money2)
{
    Money money;

    money.Init(money1.hryvnas + money2.hryvnas,
               money1.kopiykas + money2.kopiykas);

    return money;
}

Money Money::subtract(Money money1, Money money2)
{
    Money money;

    int kopiykas = static_cast<int>(money1.kopiykas) - money2.kopiykas;
    if (kopiykas > 0)
    {
        money.Init(money1.hryvnas - money2.hryvnas,
                   static_cast<unsigned char>(kopiykas));
        return money;
    }

    money.Init(money1.hryvnas - money2.hryvnas - 1,
               static_cast<unsigned char>(kopiykas + 100));
    return money;
}

double Money::divide(Money money1, Money money2)
{
    double value = money2.hryvnas + money2.kopiykas / 100.0;
    return money1.hryvnas / value + money1.kopiykas / value / 100.0;
}

Money Money::divide(Money money, double value)
{
    double res = (money.hryvnas + money.kopiykas / 100.0) / value;

    Money moneyRes;
    moneyRes.hryvnas = static_cast<long>(res);
    int kopiykas = static_cast<int>((res - moneyRes.hryvnas) * 100);
    moneyRes.kopiykas = static_cast<unsigned char>(kopiykas);

    return moneyRes;
}

Money Money::multiply(Money money, double value)
{
    double res = (money.hryvnas + money.kopiykas / 100.0) * value;

    Money moneyRes;
    moneyRes.hryvnas = static_cast<long>(res);
    int kopiykas = static_cast<int>((res - moneyRes.hryvnas) * 100);
    moneyRes.kopiykas = static_cast<unsigned char>(kopiykas);

    return moneyRes;
}

bool Money::isEqual(Money money1, Money money2)
{
    return money1.hryvnas == money2.hryvnas
           && money1.kopiykas == money2.kopiykas;
}

bool Money::isMore(Money money1, Money money2)
{
    if (money1.hryvnas > money2.hryvnas)
        return true;

    if (money1.hryvnas == money2.hryvnas)
        return money1.kopiykas > money2.kopiykas;

    return false;
}

bool Money::isLess(Money money1, Money money2)
{
    return !isEqual(money1, money2) && !isMore(money1, money2);
}
