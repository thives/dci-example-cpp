#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include <string>

namespace Data
{
	class CheckingAccount
	{
	public:
		CheckingAccount(double openingBalance);
		double balance() const;
		double increment(double amount);
		std::string name() const;
		std::string description() const;
	private:
		double m_balance;
	};
}

#endif
