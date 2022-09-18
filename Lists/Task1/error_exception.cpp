#include "error_exception.h"
#include <iostream>
error_exception::error_exception(std::string what) : std::invalid_argument(what) {
	
}
