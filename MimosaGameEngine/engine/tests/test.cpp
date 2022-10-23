#include "test.h"

void tests::initTests()
{
	// vec3 operator tests

	// vec3 == vec3
	tests.push_back([]() {
		vec3 lhs = vec3(1.f, 2.f, 3.f);
		vec3 rhs = vec3(1.f, 2.f, 3.f);

		asrt::AssertTrue(lhs == rhs, "vec3 == vec3", "true", (lhs == rhs) ? "true" : "false");
	});

	// vec3 == vec3
	tests.push_back([]() {
		vec3 lhs = vec3(1.f, 2.f, 3.f);
		vec3 rhs = vec3(2.f, 4.f, 4.f);

		asrt::AssertTrue(!(lhs == rhs), "vec3 == vec3", "false", (lhs == rhs) ? "true" : "false");
	});

	// (std::string)vec3
	tests.push_back([]() {
		vec3 v = vec3(1.15f, 2.489f, 3.7f);

		asrt::AssertTrue((std::string)v == "{1.15, 2.489, 3.7}", "(std::string)vec3", "\"{1.15, 2.489, 3.7}\"", (std::string)v);
	});

	// vec3 += vec3
	tests.push_back([]() {
		vec3 lhs = vec3(1.f, 2.f, 3.f);
		vec3 rhs = vec3(1.f, 2.f, 3.f);
		vec3 r = lhs + rhs;
		
		asrt::AssertTrue(r == vec3(2.f, 4.f, 6.f), "vec3 + vec3", "{2, 4, 6}", r);
	});

	// vec3 + float
	tests.push_back([]() {
		vec3 lhs = vec3(1.f, 2.f, 3.f);
		vec3 r = lhs + 2.f;

		asrt::AssertTrue(r == vec3(3.f, 4.f, 5.f), "vec3 + float", "{3, 4, 5}", r);
	});

	// vec3 - vec3
	tests.push_back([]() {
		vec3 lhs = vec3(1.f, 2.f, 3.f);
		vec3 rhs = vec3(2.f, 0.f, 2.f);
		vec3 r = lhs - rhs;

		asrt::AssertTrue(r == vec3(-1.f, 2.f, 1.f), "vec3 - vec3", "{-1, 2, 1}", r);
	});

	// vec3 - float
	tests.push_back([]() {
		vec3 lhs = vec3(1.f, 2.f, 3.f);
		vec3 r = lhs - 2.f;

		asrt::AssertTrue(r == vec3(-1.f, 0.f, 1.f), "vec3 - float", "{-1, 0, 1}", r);
	});

	// vec3 * vec3
	tests.push_back([]() {
		vec3 lhs = vec3(1.f, 2.f, 3.f);
		vec3 rhs = vec3(2.f, 0.f, 2.f);
		vec3 r = lhs * rhs;

		asrt::AssertTrue(r == vec3(2.f, 0.f, 6.f), "vec3 * vec3", "{2, 0, 6}", r);
	});

	// vec3 * float
	tests.push_back([]() {
		vec3 lhs = vec3(1.f, 2.f, 3.f);
		vec3 r = lhs * 2.f;

		asrt::AssertTrue(r == vec3(2.f, 4.f, 6.f), "vec3 * float", "{2, 4, 6}", r);
	});

	// vec3 / vec3
	tests.push_back([]() {
		vec3 lhs = vec3(1.f, 2.f, 3.f);
		vec3 rhs = vec3(2.f, 1.f, 2.f);
		vec3 r = lhs / rhs;

		asrt::AssertTrue(r == vec3(0.5f, 2.0f, 1.5f), "vec3 / vec3", "{0.5, 2, 1.5}", r);
	});

	// vec3 / float
	tests.push_back([]() {
		vec3 lhs = vec3(1.f, 2.f, 3.f);
		vec3 r = lhs / 2.f;

		asrt::AssertTrue(r == vec3(0.5f, 1.0f, 1.5f), "vec3 / float", "{0.5, 1, 1.5}", r);
	});

	// mat4x4 tests

	// mat4x4f::identity()
	tests.push_back([]() {
		mat4x4f mat;
		mat.identity();

		vec3 r = vec3(1.f, 2.f, 3.f);

		r *= mat;

		asrt::AssertTrue(r == vec3(1.f, 2.f, 3.f), "mat4x4f::identity()", "{1, 2, 3}", r);
	});

	// Cannot figure out how to test mat4x4f::perspective(),
	// so it is omitted, to be tested manually

	// mat4x4f::translate()
	tests.push_back([]() {
		mat4x4f mat;
		mat.translate(vec3(20.f, 15.f, 3.f));

		vec3 r = vec3(2.f, 4.f, 3.f);

		r *= mat;

		asrt::AssertTrue(r == vec3(22.f, 19.f, 6.f), "mat4x4f::translate()", "{22, 19, 6}", r);
	});

	// Logger tests

	// All other functions are omitted,
	// because tests are not needed for
	// said functions

	// Logger::serialize() : std::string
	tests.push_back([]() {
		Logger logger = Logger(false);

		std::any input = (std::string)"abc";

		std::string r = logger.serialize(input);

		asrt::AssertTrue(r == "abc", "Logger::serialize() : std::string", "\"abc\"", r);
	});

	// Logger::serialize() : int
	tests.push_back([]() {
		Logger logger = Logger(false);

		std::any input = 1234;

		std::string r = logger.serialize(input);

		asrt::AssertTrue(r == "1234", "Logger::serialize() : int", "\"1234\"", r);
	});

	// Logger::serialize() : float
	tests.push_back([]() {
		Logger logger = Logger(false);

		std::any input = 1.234f;

		std::string r = logger.serialize(input);

		asrt::AssertTrue(r == "1.234000", "Logger::serialize() : float", "\"1.234000\"", r);
	});

	// Logger::serialize() : double
	tests.push_back([]() {
		Logger logger = Logger(false);

		std::any input = 1.234;

		std::string r = logger.serialize(input);

		asrt::AssertTrue(r == "1.234000", "Logger::serialize() : double", "\"1.234000\"", r);
	});

	// Logger::serialize() : bool
	tests.push_back([]() {
		Logger logger = Logger(false);

		std::any input = true;

		std::string r = logger.serialize(input);

		asrt::AssertTrue(r == "true", "Logger::serialize() : bool", "\"true\"", r);
	});

	// Logger::serialize() : bool
	tests.push_back([]() {
		Logger logger = Logger(false);

		std::any input = true;

		std::string r = logger.serialize(input);

		asrt::AssertNotTrue(r == "false", "Logger::serialize() : bool", "\"false\"", r);
	});

	// Logger::serialize() : invalid
	tests.push_back([]() {
		Logger logger = Logger(false);

		std::any input = logger;

		std::string r = logger.serialize(input);

		asrt::AssertTrue(r == "Invalid Type", "Logger::serialize() : invalid", "\"Invalid Type\"", r);
	});

	// example test
	//tests.push_back([]() {
	//    std::string r = "actual result";
	//    
	//    asrt::AssertTrue(r == "expected result", "example test name", "expected result (formatted as string)", r);
	//});
}

bool tests::runTests()
{
	unsigned int numFail = 0;

	int i = 0;
	for (auto &t : tests)
	{
		std::stringstream percentageString;
		percentageString << std::setprecision(3) << ((float)i / tests.size()) * 100;

		std::cout << "Tests Done: " << percentageString.str() << "%\r";
		std::flush(std::cout);

		try {
			t();
		}
		catch (asrt::AssertException e) {
			std::cout << "Test Failed:      \n" << e.what() << "\n";
			numFail++;
		}
		
		i++;
	}
	std::cout << "                    \n\n";

	if (numFail == 0) {
		std::cout << "All tests passed.\n";
		return true;
	}

	std::cout << numFail << " / " << tests.size() << " tests failed, or ";

	std::stringstream percentageString;
	percentageString << std::setprecision(3) << ((float)numFail / tests.size()) * 100 << "% tests failed.\n";
	std::cout << percentageString.str();

	return false;
}

int tests::testMain()
{
	initTests();
	if (!runTests()) {
		return -2;
	}
	return 0;
}