#include "sayhello.h"
#include "gtest/gtest.h"
#include <sstream>
namespace {
TEST(HelloTest, sayHelloSaysHello) {
    std::ostringstream out{};
    sayhello(out);
    ASSERT_EQ("Hello, world!", out.str());
}
}
