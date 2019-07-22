#include "logger.h"
#include <iostream>

Logger* Logger::writeLine(const std::string& text)
{
	std::cout << text << std::endl;
	return this;
}
