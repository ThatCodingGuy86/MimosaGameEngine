#include "log.h"

// Implementation of Logger::log() in log.h
void Logger::log(std::string str)
{
	std::cout << "[LOG]: " << str;
	m_log.append("[LOG]: ");
	m_log.append(str);
}

// Implementation of Logger::warn() in log.h
void Logger::warn(std::string str)
{
	// Draw the "[WARN]: " text white
	std::cout << "[WARN]: ";
	m_log.append("[WARN]: ");

	HANDLE c = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(c, FOREGROUND_RED | FOREGROUND_GREEN);

	std::cout << str;

	SetConsoleTextAttribute(c, (FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN));
}

// Implementation of Logger::err() in log.h
void Logger::err(std::string str)
{
	// Draw the "[ERR]: " text white
	std::cout << "[ERR]: ";
	m_log.append("[ERR]: ");

	HANDLE c = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(c, FOREGROUND_RED);

	std::cout << str;
	m_log.append(str);

	SetConsoleTextAttribute(c, (FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN));
}

// Implementation of Logger::dumpLog() in log.h
bool Logger::dumpLog()
{
	std::ofstream file = std::ofstream("log.txt");

	if (file.is_open())
		file << m_log;
	else
	{
		file.close();
		err("Failed to open log file\n");
		return false;
	}
		
	file.close();

	std::cout << "Log file log.txt dumped to EXE directory\n";
	return true;
}