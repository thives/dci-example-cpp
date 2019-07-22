#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include <string>

namespace Data
{
	class SavingsAccount
	{
	public:
		SavingsAccount(double openingBalance);
		double balance() const;
		double decrement(double amount);
		std::string name() const;
	private:
		double m_balance;
	};
}

#endif
