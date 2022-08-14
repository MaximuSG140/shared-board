#pragma once
#include "pch.h"


class Logger
{
public:
	enum class LogLevel
	{
		DEBUG,
		INFO,
		WARNING,
		ERROR,
		FATAL
	};

	static void log(LogLevel level, const std::string& message);

private:
	inline const static  std::map<LogLevel, std::string> LEVEL_TO_STRING = {
		{LogLevel::DEBUG, "[DEBUG]"},
		{LogLevel::INFO, "[INFO]"},
		{LogLevel::WARNING, "[WARNING]"},
		{LogLevel::ERROR, "[ERROR]"},
		{LogLevel::FATAL, "[FATAL]"}
	};

	inline static std::mutex output_locker_;
};