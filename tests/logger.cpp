#include <string>

#include "test_harness.h"
#include "../src/logger.h"

TEST(logger_check, null)
{
    chrmi::Logger logger;
    const std::string msg = "cats";
    auto log = logger.log(msg);
    CHECK_EQUAL(log.first, "cats");
}
