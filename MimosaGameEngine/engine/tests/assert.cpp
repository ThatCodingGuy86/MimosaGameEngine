#include "assert.h"

asrt::AssertException::AssertException() { reason = "asrt::AssertException"; };
asrt::AssertException::AssertException(std::string _reason) { reason = _reason; };
const char* asrt::AssertException::what() { return reason.c_str(); }

// Template functions omitted as they cannot be defined in the .cpp file