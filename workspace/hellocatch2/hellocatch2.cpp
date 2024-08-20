#include "sayhello.h"
#include "catch2/catch_all.hpp"
#include <sstream>
namespace {
TEST_CASE("HelloTest", "sayHelloSaysHello") {
    std::ostringstream out{};
    sayhello(out);
    REQUIRE(out.str() == "Hello, world!" );
}
}
