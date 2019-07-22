#ifndef MONEYTRANSFERCONTEXT_H
#define MONEYTRANSFERCONTEXT_H

#include <string>

namespace MoneyTransferContext
{
	using namespace std::literals;
	
	template<typename T> concept bool ACCOUNT_Constraint = requires(T a) {
		{ a.balance() } -> double;
		{ a.name() } -> std::string;
		{ a.description() } -> std::string;
	};
	
	template<typename T> concept bool SOURCE_Constraint = requires(T a) {
		requires ACCOUNT_Constraint<T>;
		{ a.decrement(0.0) } -> double;
	};
	
	template<typename T> concept bool SINK_Constraint = requires(T a) {
		requires ACCOUNT_Constraint<T>;
		{ a.increment(0.0) } -> double;
	};
	
	template<typename T, typename U> concept bool LOGGER_Constraint = requires(T a, U b) {
		{ a.writeLine(""s) } -> T*;
		{ a.write(&b) } -> T*;
	};

	template<typename SOURCE, typename SINK, typename LOGGER> requires
	SOURCE_Constraint<SOURCE> &&
	SINK_Constraint<SINK> &&
	LOGGER_Constraint<LOGGER, SOURCE> &&
	LOGGER_Constraint<LOGGER, SINK>
	class MoneyTransferObject 
	{
	public:
		MoneyTransferObject(SOURCE* sourceObject, SINK* sinkObject, LOGGER* loggerObject) :
		m_source(sourceObject),
		m_sink(sinkObject),
		m_logger(loggerObject)
		{
		}
		void transfer()
		{
			m_logger->write(m_source);
			m_logger->write(m_sink);
			m_source->decrement(amount);
			m_sink->increment(amount);
			m_logger->writeLine("Transferred "s + 
				std::to_string(amount) + 
				" from "s + m_source->name() + 
				" to "s + m_sink->name());
			m_logger->write(m_source);
			m_logger->write(m_sink);
		}
		
		double amount;
	private:
		SOURCE* m_source;
		SINK* m_sink;
		LOGGER* m_logger;
	};
}

#endif
