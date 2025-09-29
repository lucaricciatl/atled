#include "ProgressBar.hpp"
#include "gtest/gtest.h"
#include <sstream>
#include <iostream>

// Test that finish() prints complete progress and ends with a newline.
TEST(ProgressBarTest, FinishPrintsFullProgress) {
    // Redirect std::cout to capture output.
    std::streambuf* orig_buf = std::cout.rdbuf();
    std::ostringstream capturedOutput;
    std::cout.rdbuf(capturedOutput.rdbuf());

    logging::ProgressBar progressBar(100, 10);
    progressBar.finish();

    // Restore std::cout.
    std::cout.rdbuf(orig_buf);
    std::string output = capturedOutput.str();

    // Check the output contains a complete progress bar ("[==========] 100 %") 
    // and ends with a newline.
    ASSERT_NE(output.find("[==========] 100 %"), std::string::npos);
    ASSERT_EQ(output.back(), '\n');
}

// Test that update() correctly reflects intermediate progress.
TEST(ProgressBarTest, UpdatePrints) {
    logging::ProgressBar progressBar(100, 50);
    for (int i = 0; i <= 100; ++i) {
        progressBar.update(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(1)); // Adjust delay as needed
    }
    progressBar.finish();
}

TEST(ProgressBarTest, UpdateHandlesOutOfBounds) {
    std::streambuf* orig_buf = std::cout.rdbuf();
    std::ostringstream capturedOutput;
    std::cout.rdbuf(capturedOutput.rdbuf());

    logging::ProgressBar progressBar(100, 10);
    progressBar.update(-10);  // Below 0
    progressBar.update(150);  // Above total

    std::cout.rdbuf(orig_buf);
    std::string output = capturedOutput.str();

    // Check that '0 %' and '100 %' are present in the output.
    ASSERT_NE(output.find("0 %"), std::string::npos);
    ASSERT_NE(output.find("100 %"), std::string::npos);
}