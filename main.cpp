#include "moneytransfercontext.h"
#include "savingsaccount.h"
#include "checkingaccount.h"
#include "logger.h"
#include "accountlogger.h"

template<class T> concept bool MONEYTRANSFER_Constraint = requires(T a) {
	{ a.transfer() };
	requires std::is_same<decltype(a.amount), double>::value;
};

template<class MONEYTRANSFER> requires MONEYTRANSFER_Constraint<MONEYTRANSFER>
void doTransfer(MONEYTRANSFER* moneyTransfer)
{
	moneyTransfer->amount = 30.0;
	moneyTransfer->transfer();
}

int main(int argc, char** argv)
{
	auto savingsAccount = new Data::SavingsAccount(100.0);
	auto checkingAccount = new Data::CheckingAccount(20.0);
	auto logger = new Logger();
	auto accountLogger = new AccountLoggerContext::AccountLoggerObject(logger);
	auto moneyTransfer = new MoneyTransferContext::MoneyTransferObject(savingsAccount, checkingAccount, accountLogger);

	doTransfer(moneyTransfer);

	delete moneyTransfer;
	delete accountLogger;
	delete logger;
	delete checkingAccount;
	delete savingsAccount;
	return 0;
}
