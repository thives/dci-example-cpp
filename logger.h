#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger 
{
public:
	Logger* writeLine(const std::string& text);
};

#endif
