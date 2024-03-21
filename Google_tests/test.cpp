//
// Created by Max on 19.03.2024.
//

#include "gtest/gtest.h"
#include "../Account.h"

TEST(AccountTestSuite, AccountTest)
{
    Money money;
    money.Init(1992, 28);
    Account account;
    account.Init("Pirozhak", "UA213223130000026007233566001",
                 5, money);

    EXPECT_EQ(account.toString(),
              "(Pirozhak;UA213223130000026007233566001;5;1992,28)");
    EXPECT_EQ(account.toTextString(),
              "one thousand nine hundred ninety two hrn. 28 kop.");
}
