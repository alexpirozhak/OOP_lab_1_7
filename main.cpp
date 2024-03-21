#include <iostream>
#include "Account.h"

using namespace std;

int main()
{
    Account account;
    account.Read();
    cout << endl;

    cout << "You entered: ";
    account.Display();
    cout << "Text money representation: " << account.toTextString() << endl;
    cout << "Dollars: " << account.toDollars().toString() << endl;
    cout << "Euros: " << account.toEuros().toString() << endl << endl;

    account.creditPercentage();
    cout << "Percentage credited: ";
    account.Display();
    cout << endl;

    string surname;
    cout << "Enter new card owner: ";
    cin >> surname;
    account.changeOwner(surname);

    Money withdraw, put;
    cout << "Enter value to withdraw:" << endl;
    withdraw.Read();
    cout << "Enter value to put:" << endl;
    put.Read();
    account.withdrawCash(withdraw);
    account.putCash(put);
    account.Display();
    cout << endl;

    return 0;
}
