#include "checkingaccount.h"

using namespace std::literals;

namespace Data
{
CheckingAccount::CheckingAccount(double openingBalance) :
m_balance(openingBalance)
{
}

double CheckingAccount::balance() const
{
	return m_balance;
}

double CheckingAccount::increment(double amount)
{
	m_balance += amount;
	return m_balance;
}

std::string CheckingAccount::name() const
{
	return "Checking account"s;
}
}
