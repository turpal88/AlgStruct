#pragma once
#include <stdexcept>
class error_exception : public std::invalid_argument {
public:
	error_exception(std::string what);
};