#include "savingsaccount.h"

using namespace std::literals;

namespace Data
{
SavingsAccount::SavingsAccount(double openingBalance) :
m_balance(openingBalance)
{
}

double SavingsAccount::balance() const
{
	return m_balance;
}

double SavingsAccount::decrement(double amount)
{
	m_balance -= amount;
	return m_balance;
}

std::string SavingsAccount::name() const
{
	return "Savings account"s;
}

std::string SavingsAccount::description() const
{
	return "Savings account"s;
}
}
