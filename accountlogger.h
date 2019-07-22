#ifndef ACCOUNTLOGGER_H
#define ACCOUNTLOGGER_H

#include <string>

namespace AccountLoggerContext
{
	using namespace std::literals;
	template<typename T> concept bool ACCOUNT_Constraint = requires(T a) {
		{ a.balance() } -> double;
		{ a.name() } -> std::string;
	};
	template<typename T> concept bool LOGGER_Constraint = requires(T a) {
		{ a.writeLine(""s) } -> T*;
	};
template<typename LOGGER> requires 
LOGGER_Constraint<LOGGER>
class AccountLoggerObject
{
public:
	AccountLoggerObject(LOGGER* loggerObject) : m_logger(loggerObject) {}
	
	template<typename ACCOUNT> requires
	ACCOUNT_Constraint<ACCOUNT>
	AccountLoggerObject* write(ACCOUNT* accountObject)
	{
		m_logger->writeLine("Balance of "s + 
				accountObject->name() +
				": "s +
				std::to_string(accountObject->balance()));
		return this;
	}
	AccountLoggerObject* writeLine(const std::string& text)
	{
		m_logger->writeLine(text);
		return this;
	}
private:
	LOGGER* m_logger;
};
}

#endif
