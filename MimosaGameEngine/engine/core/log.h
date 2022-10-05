#pragma once
#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>

// A small logging library. Windows only, I might add Linux & MacOS compatibility
// when I need it for my own programs, but I don't really want to spend time on dealing
// with Linux & MacOS when I don't need to.

// Free to copy, preferably with credit, but I don't mind if you don't give credit. 

class Logger
{
protected:
	std::string m_log;
public:
	// Prints '[LOG]: str'
	void log(std::string str);

	// Prints '[WARN]: str' in yellow text (indicates a warning)
	void warn(std::string str);

	// Prints '[ERR]: str' in red text (indicates an error)
	void err(std::string str);

	// Dumps the log to the working directory. Returns true if successful
	bool dumpLog();
};

