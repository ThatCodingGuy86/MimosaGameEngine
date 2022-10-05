#pragma once
#include <exception>
#include <string>

namespace asrt {
	// Used for detecting assert failures
	class AssertException : public std::exception {
		std::string reason;
	public:
		AssertException();
		AssertException(std::string _reason);

		const char* what();
	};

	// Checks if v is true. If not, throws a AssertException with a formatted reason
	template<class T> void AssertTrue(bool v, std::string testName, std::string expected, T actual) {
		if (v != true) {
			std::string reason = "Test ";
			reason.append(testName);
			reason.append(" failed: \nExpected Result: ");
			reason.append(expected);
			reason.append("\nActual Result: ");
			reason.append((std::string)actual);
			reason.append("\n");
			throw AssertException(reason);
		}
	}

	// Checks if v is not true. If not, throws a AssertException with a formatted reason
	template<class T> void AssertNotTrue(bool v, std::string testName, std::string expected, T actual) {
		if (v == true) {
			std::string reason = "Test ";
			reason.append(testName);
			reason.append(" failed: \nExpected Result: ");
			reason.append(expected);
			reason.append("\nActual Result: ");
			reason.append((std::string)actual);
			reason.append("\n");
			throw AssertException(reason);
		}
	}
}