#include "sayhello.h"
#include "doctest.h"
#include <sstream>
namespace {
TEST_CASE("HelloTest", "sayHelloSaysHello") {
	std::ostringstream os{};
	sayhello(os);
	REQUIRE(os.str() == "Hello, world!" );
}
}
