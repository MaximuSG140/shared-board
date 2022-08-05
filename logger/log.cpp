#include "pch.h"

#include "log.h"

void Logger::log(const LogLevel level, const std::string& message)
{
	using namespace std::chrono;
	std::lock_guard lock(output_locker_);
	auto current_time = system_clock::now();
	auto converted_time_t = system_clock::to_time_t(current_time);
	auto time_string = std::localtime(&converted_time_t);
	std::cout << LEVEL_TO_STRING.at(level) << " " <<
		std::put_time(time_string, "%d:%m:%Y %H:%M:S: ") << message << std::endl;
}
