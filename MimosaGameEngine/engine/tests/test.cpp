#include "test.h"
#include "../core/ecs/component.h"

void tests::initUnitTests()
{
	// vec3 operator tests

	// vec3 == vec3
	unitTests.push_back([]() {
		vec3 lhs = vec3(1.f, 2.f, 3.f);
		vec3 rhs = vec3(1.f, 2.f, 3.f);

		asrt::AssertTrue(lhs == rhs, "vec3 == vec3", "true", (lhs == rhs) ? "true" : "false");
	});

	// vec3 == vec3
	unitTests.push_back([]() {
		vec3 lhs = vec3(1.f, 2.f, 3.f);
		vec3 rhs = vec3(2.f, 4.f, 4.f);

		asrt::AssertTrue(!(lhs == rhs), "vec3 == vec3", "false", (lhs == rhs) ? "true" : "false");
	});

	// (std::string)vec3
	unitTests.push_back([]() {
		vec3 v = vec3(1.15f, 2.489f, 3.7f);

		asrt::AssertTrue((std::string)v == "{1.15, 2.489, 3.7}", "(std::string)vec3", "\"{1.15, 2.489, 3.7}\"", (std::string)v);
	});

	// vec3 += vec3
	unitTests.push_back([]() {
		vec3 lhs = vec3(1.f, 2.f, 3.f);
		vec3 rhs = vec3(1.f, 2.f, 3.f);
		vec3 r = lhs + rhs;
		
		asrt::AssertTrue(r == vec3(2.f, 4.f, 6.f), "vec3 + vec3", "{2, 4, 6}", r);
	});

	// vec3 + float
	unitTests.push_back([]() {
		vec3 lhs = vec3(1.f, 2.f, 3.f);
		vec3 r = lhs + 2.f;

		asrt::AssertTrue(r == vec3(3.f, 4.f, 5.f), "vec3 + float", "{3, 4, 5}", r);
	});

	// vec3 - vec3
	unitTests.push_back([]() {
		vec3 lhs = vec3(1.f, 2.f, 3.f);
		vec3 rhs = vec3(2.f, 0.f, 2.f);
		vec3 r = lhs - rhs;

		asrt::AssertTrue(r == vec3(-1.f, 2.f, 1.f), "vec3 - vec3", "{-1, 2, 1}", r);
	});

	// vec3 - float
	unitTests.push_back([]() {
		vec3 lhs = vec3(1.f, 2.f, 3.f);
		vec3 r = lhs - 2.f;

		asrt::AssertTrue(r == vec3(-1.f, 0.f, 1.f), "vec3 - float", "{-1, 0, 1}", r);
	});

	// vec3 * vec3
	unitTests.push_back([]() {
		vec3 lhs = vec3(1.f, 2.f, 3.f);
		vec3 rhs = vec3(2.f, 0.f, 2.f);
		vec3 r = lhs * rhs;

		asrt::AssertTrue(r == vec3(2.f, 0.f, 6.f), "vec3 * vec3", "{2, 0, 6}", r);
	});

	// vec3 * float
	unitTests.push_back([]() {
		vec3 lhs = vec3(1.f, 2.f, 3.f);
		vec3 r = lhs * 2.f;

		asrt::AssertTrue(r == vec3(2.f, 4.f, 6.f), "vec3 * float", "{2, 4, 6}", r);
	});

	// vec3 / vec3
	unitTests.push_back([]() {
		vec3 lhs = vec3(1.f, 2.f, 3.f);
		vec3 rhs = vec3(2.f, 1.f, 2.f);
		vec3 r = lhs / rhs;

		asrt::AssertTrue(r == vec3(0.5f, 2.0f, 1.5f), "vec3 / vec3", "{0.5, 2, 1.5}", r);
	});

	// vec3 / float
	unitTests.push_back([]() {
		vec3 lhs = vec3(1.f, 2.f, 3.f);
		vec3 r = lhs / 2.f;

		asrt::AssertTrue(r == vec3(0.5f, 1.0f, 1.5f), "vec3 / float", "{0.5, 1, 1.5}", r);
	});

	// mat4x4 tests

	// mat4x4f::identity()
	unitTests.push_back([]() {
		mat4x4f mat;
		mat.identity();

		vec3 r = vec3(1.f, 2.f, 3.f);

		r *= mat;

		asrt::AssertTrue(r == vec3(1.f, 2.f, 3.f), "mat4x4f::identity()", "{1, 2, 3}", r);
	});

	// Cannot figure out how to test mat4x4f::perspective(),
	// so it is omitted, to be tested manually

	// mat4x4f::translate()
	unitTests.push_back([]() {
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
	unitTests.push_back([]() {
		Logger logger = Logger(false);

		std::any input = (std::string)"abc";

		std::string r = logger.serialize(input);

		asrt::AssertTrue(r == "abc", "Logger::serialize() : std::string", "\"abc\"", r);
	});

	// Logger::serialize() : int
	unitTests.push_back([]() {
		Logger logger = Logger(false);

		std::any input = 1234;

		std::string r = logger.serialize(input);

		asrt::AssertTrue(r == "1234", "Logger::serialize() : int", "\"1234\"", r);
	});

	// Logger::serialize() : float
	unitTests.push_back([]() {
		Logger logger = Logger(false);

		std::any input = 1.234f;

		std::string r = logger.serialize(input);

		asrt::AssertTrue(r == "1.234000", "Logger::serialize() : float", "\"1.234000\"", r);
	});

	// Logger::serialize() : double
	unitTests.push_back([]() {
		Logger logger = Logger(false);

		std::any input = 1.234;

		std::string r = logger.serialize(input);

		asrt::AssertTrue(r == "1.234000", "Logger::serialize() : double", "\"1.234000\"", r);
	});

	// Logger::serialize() : bool
	unitTests.push_back([]() {
		Logger logger = Logger(false);

		std::any input = true;

		std::string r = logger.serialize(input);

		asrt::AssertTrue(r == "true", "Logger::serialize() : bool", "\"true\"", r);
	});

	// Logger::serialize() : bool
	unitTests.push_back([]() {
		Logger logger = Logger(false);

		std::any input = true;

		std::string r = logger.serialize(input);

		asrt::AssertNotTrue(r == "false", "Logger::serialize() : bool", "\"false\"", r);
	});

	// Logger::serialize() : invalid
	unitTests.push_back([]() {
		Logger logger = Logger(false);

		std::any input = logger;

		std::string r = logger.serialize(input);

		asrt::AssertTrue(r == "Invalid Type", "Logger::serialize() : invalid", "\"Invalid Type\"", r);
	});

	// ecs::Component tests

	// ecs::Component::Component()
	unitTests.push_back([]() {
		ecs::Component comp = ecs::Component("test name");
		std::string r = comp.name;
	    
	    asrt::AssertTrue(r == "test name", "ecs::Component::Component()", "test name", r);
	});

	// ecs::Component::GetID()
	unitTests.push_back([]() {
		ecs::Component comp = ecs::Component("test name");

		comp.InitID(0);
		uint32_t r = comp.GetID();

		asrt::AssertTrue(r == 0, "ecs::Component::GetID()", "0", std::to_string(r));
	});

	// ecs::Component::InitID() : multi init fail cond.
	unitTests.push_back([]() {
		ecs::Component comp = ecs::Component("test name");

		comp.InitID(0);
		comp.InitID(1);
		uint32_t r = comp.GetID();

		asrt::AssertTrue(r == 0, "ecs::Component::InitID() : multi init fail cond.", "0", std::to_string(r));
	});

	// example test
	//unitTests.push_back([]() {
	//    std::string r = "actual result";
	//    
	//    asrt::AssertTrue(r == "expected result", "example test name", "expected result (formatted as string)", r);
	//});
}

void tests::initPrefTests()
{
	// Example test
	//prefTests.push_back([]() {
	//	auto startTimePrev = std::chrono::high_resolution_clock::now();

	//	for (int i = 0; i < 1000; i++)
	//	{
	//		// Call previous code here
	//	}

	//	auto endTimePrev = std::chrono::high_resolution_clock::now();
	//	auto r_prev = std::chrono::duration_cast<std::chrono::milliseconds>(endTimePrev - startTimePrev).count();

	//	auto startTime = std::chrono::high_resolution_clock::now();

	//	for (int i = 0; i < 1000; i++)
	//	{
	//		// Call new code here
	//	}

	//	auto endTime = std::chrono::high_resolution_clock::now();
	//	auto r = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();

	//	asrt::AssertTrue(r < r_prev, "example test name", "r < r_prev", std::to_string(r) + " : " + std::to_string(r_prev));
	//});
}

bool tests::runUnitTests()
{
	unsigned int numFail = 0;

	int i = 0;
	for (auto &t : unitTests)
	{
		std::stringstream percentageString;
		percentageString << std::setprecision(3) << ((float)i / unitTests.size()) * 100;

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

	std::cout << numFail << " / " << unitTests.size() << " tests failed, or ";

	std::stringstream percentageString;
	percentageString << std::setprecision(3) << ((float)numFail / unitTests.size()) * 100 << "% tests failed.\n";
	std::cout << percentageString.str();

	return false;
}

bool tests::runPrefTests()
{
	unsigned int numFail = 0;

	int i = 0;
	for (auto& t : prefTests)
	{
		std::stringstream percentageString;
		percentageString << std::setprecision(3) << ((float)i / prefTests.size()) * 100;

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

	std::cout << numFail << " / " << prefTests.size() << " tests failed, or ";

	std::stringstream percentageString;
	percentageString << std::setprecision(3) << ((float)numFail / prefTests.size()) * 100 << "% tests failed.\n";
	std::cout << percentageString.str();

	return false;
}

int tests::testMain()
{
	// Disable output for the logger, as some tested functions output logs
	logger->output = false;
	initUnitTests();
	initPrefTests();

	bool bRunUnitTests = false;
	bool bRunPrefTests = false;

	bool responseInvalid = true;
	while (responseInvalid)
	{
		std::cout << "Run only Unit Tests [a], only Preformace Tests [b], or both? [c]\n";

		std::string response;
		std::cin >> response;

		switch (toupper(response[0]))
		{
		case 'A':
			bRunUnitTests = true;
			responseInvalid = false;
			break;
		case 'B':
			bRunPrefTests = true;
			responseInvalid = false;
			break;
		case 'C':
			bRunUnitTests = true;
			bRunPrefTests = true;
			responseInvalid = false;
			break;
		default:
			std::cout << "Invalid response. Please enter a, b, or c.\n";
			break;
		}
	}

	bool unitTestsFailed = false;
	bool prefTestsFailed = false;

	if (bRunUnitTests)
	{
		if (!runUnitTests()) {
			unitTestsFailed = true;
		}
	}

	if (bRunPrefTests)
	{
		if (!runPrefTests()) {
			prefTestsFailed = true;
		}
	}

	int returnVal = 0;

	if (unitTestsFailed)
	{
		returnVal |= 1;
	}

	if (prefTestsFailed)
	{
		returnVal |= 2;
	}

	// Enable output for the logger, as to not mess up things in main
	logger->output = true;

	return -returnVal;
}