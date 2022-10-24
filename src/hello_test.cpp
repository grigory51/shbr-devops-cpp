#include "hello.hpp"

#include <userver/utest/utest.hpp>

UTEST(SayHelloTo, Basic) {
  EXPECT_EQ(shbr_devops_cpp::SayHelloTo("Developer"), "Hello, Developer!\n");
  EXPECT_EQ(shbr_devops_cpp::SayHelloTo({}), "Hello, unknown user!\n");
}
