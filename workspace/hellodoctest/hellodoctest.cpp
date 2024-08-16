#include "sayhello.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include <sstream>
namespace {
TEST_CASE("sayHelloSaysHello") {
	std::ostringstream os{};
	sayhello(os);
	REQUIRE(os.str() == "Hello, world!" );
	CHECK(true);
}
}
