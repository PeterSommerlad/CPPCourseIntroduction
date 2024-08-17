#include "sayhello.h"
#include "gtest/gtest.h"
#include <sstream>
namespace {
TEST(HelloTest, sayHelloSaysHello) {
	std::ostringstream os{};
	sayhello(os);
	ASSERT_EQ("Hello, world!", os.str());
}
}
