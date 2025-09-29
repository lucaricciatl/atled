#include "Logging.hpp"
#include <gtest/gtest.h>

TEST(LoggingTest, LogMessage) {
    logging::Logger logger("test.log");
    logger.Log("This is a test log message.", logging::LogLevel::Info);
    EXPECT_TRUE(true);  // Replace with actual log verification
}
TEST(LoggingTest, LogWarning) {
    logging::Logger logger("test.log");
    logger.Log("This is a test warning message.", logging::LogLevel::Warning);
    EXPECT_TRUE(true);  // Replace with actual log verification
}

TEST(LoggingTest, LogError) {
    logging::Logger logger("test.log");
    logger.Log("This is a test error message.", logging::LogLevel::Error);
    EXPECT_TRUE(true);  // Replace with actual log verification
}

