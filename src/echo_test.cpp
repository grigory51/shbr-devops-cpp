#include "echo.hpp"

#include <userver/utest/utest.hpp>

UTEST(MakeEcho, Basic) {
  EXPECT_EQ(shbr_devops_cpp::MakeEcho("Developer"), "Developer");
  EXPECT_EQ(shbr_devops_cpp::MakeEcho({}), "");
}
