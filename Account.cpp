//
// Created by Max on 19.03.2024.
//

#include "Account.h"

string Account::digitToText(int digit)
{
    switch (digit)
    {
        case 1:
            return "one";
        case 2:
            return "two";
        case 3:
            return "three";
        case 4:
            return "four";
        case 5:
            return "five";
        case 6:
            return "six";
        case 7:
            return "seven";
        case 8:
            return "eight";
        case 9:
            return "nine";
        default:
            return "";
    }
}

string Account::teenToText(int teen)
{
    switch (teen)
    {
        case 10:
            return "ten";
        case 11:
            return "eleven";
        case 12:
            return "twelve";
        case 13:
            return "thirteen";
        case 14:
            return "fourteen";
        case 15:
            return "fifteen";
        case 16:
            return "sixteen";
        case 17:
            return "seventeen";
        case 18:
            return "eighteen";
        case 19:
            return "nineteen";
        default:
            return "";
    }
}

string Account::tensToText(int tens)
{
    switch (tens)
    {
        case 2:
            return "twenty";
        case 3:
            return "thirty";
        case 4:
            return "fourty";
        case 5:
            return "fifty";
        case 6:
            return "sixty";
        case 7:
            return "seventy";
        case 8:
            return "eighty";
        case 9:
            return "ninety";
        default:
            return "";
    }
}

string Account::classToText(int num)
{
    if (num < 0 || num >= 1000)
        return "";
    if (num < 10)
        return digitToText(num);
    if (num < 20)
        return teenToText(num);
    if (num < 100)
        return tensToText(num / 10) + " " + digitToText(num % 10);

    return digitToText(num / 100) + " hundred "
           + tensToText(num % 100 / 10)
           + " " + digitToText(num % 10);
}

string Account::getSurname() const
{
    return surname;
}

string Account::getIban() const
{
    return iban;
}

double Account::getPercentage() const
{
    return percentage;
}

bool Account::setPercentage(double percentage)
{
    if (percentage < 0 || percentage > 100)
        return false;

    this->percentage = percentage;
    return true;
}

Money Account::getMoney() const
{
    return money;
}

bool Account::Init(const string &surname, const string &iban, double percentage, Money money)
{
    this->surname = surname;
    this->iban = iban;
    this->money = money;
    return setPercentage(percentage);
}

void Account::Read()
{
    cout << "Enter surname: ";
    cin >> surname;

    cout << "Enter iban: ";
    cin >> iban;

    double percentage;
    do
    {
        cout << "Enter percentage: ";
        cin >> percentage;

        if (setPercentage(percentage))
            break;
        cout << "Invalid input. Try again..." << endl;
    } while (true);

    money.Read();
}

string Account::toString() const
{
    stringstream sout;
    sout << '(' << surname << ';' << iban << ';'
         << percentage << ';' << money.toString() << ')';

    return sout.str();
}

void Account::Display() const
{
    cout << toString() << endl;
}

void Account::changeOwner(string surname)
{
    this->surname = surname;
}

bool Account::withdrawCash(Money cash)
{
    if (Money::isMore(cash, money))
        return false;

    money = Money::subtract(money, cash);
    return true;
}

void Account::putCash(Money cash)
{
    money = Money::add(money, cash);
}

void Account::creditPercentage()
{
    money = Money::add(money,
                       Money::multiply(money,
                                       percentage / 100));
}

Money Account::toDollars() const
{
    return Money::divide(money, dollar);
}

Money Account::toEuros() const
{
    return Money::divide(money, euro);
}

string Account::toTextString() const
{
    stringstream sout;
    sout << " hrn. " << static_cast<int>(money.getKopiykas()) << " kop.";
    string res, sign, tail = sout.str();
    long hryvnas = money.getHryvnas();
    if (hryvnas < 0)
    {
        hryvnas = -hryvnas;
        sign = "minus ";
    }

    res = classToText(hryvnas % 1000);
    hryvnas /= 1000;
    if (hryvnas == 0)
        return sign + res + tail;

    res = classToText(hryvnas % 1000) + " thousand " + res;
    hryvnas /= 1000;
    if (hryvnas == 0)
        return sign + res + tail;

    res = classToText(hryvnas % 1000) + " million " + res;
    hryvnas /= 1000;
    if (hryvnas == 0)
        return sign + res + tail;

    res = classToText(hryvnas % 1000) + " billion " + res;
    hryvnas /= 1000;
    if (hryvnas == 0)
        return sign + res + tail;

    res = classToText(hryvnas % 1000) + " trillion " + res;
    hryvnas /= 1000;
    if (hryvnas == 0)
        return sign + res + tail;

    res = classToText(hryvnas % 1000) + " quadrillion " + res;
    return sign + res + tail;
}
