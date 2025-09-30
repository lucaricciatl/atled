#include <gtest/gtest.h>
#include <fstream>
#include <filesystem>
#include "FileSystemManager.hpp"

namespace fs = std::filesystem;

class FileSystemTest : public ::testing::Test {
protected:
    FileSystem fsManager;
    fs::path origPath;
    fs::path testDir;

    void SetUp() override {
        // Save the original working directory.
        origPath = fsManager.getCurrentPath();
        // Create a unique test directory inside the original path.
        testDir = origPath / "gtest_filesystem_test";
        fsManager.createDirectory(testDir);
    }

    void TearDown() override {
        // Remove the test directory if it exists.
        if (std::filesystem::exists(testDir))
            std::filesystem::remove_all(testDir);
        // Restore the original working directory.
        fsManager.setCurrentPath(origPath);
    }
};

TEST_F(FileSystemTest, CurrentPathTest) {
    // Ensure the original path is set.
    EXPECT_EQ(fsManager.getCurrentPath(), origPath);

    // Test setCurrentPath and getCurrentPath.
    std::filesystem::path tempDir = std::filesystem::temp_directory_path();
    fsManager.setCurrentPath(tempDir);
    EXPECT_EQ(fsManager.getCurrentPath(), tempDir);

    // Restore to original path.
    fsManager.setCurrentPath(origPath);
    EXPECT_EQ(fsManager.getCurrentPath(), origPath);
}

TEST_F(FileSystemTest, SearchFilesTest) {
    // Create test files in testDir.
    std::filesystem::path file1 = testDir / "testfile1.txt";
    std::filesystem::path file2 = testDir / "example.txt";
    {
        std::ofstream ofs(file1);
        ofs << "Hello world";
    }
    {
        std::ofstream ofs(file2);
        ofs << "Example content";
    }

    // Search for files matching pattern "test.*".
    auto results = fsManager.searchFiles(testDir, "test.*");
    bool foundTestFile1 = false;
    for (const auto& path : results) {
        if (path.filename() == "testfile1.txt")
            foundTestFile1 = true;
    }
    EXPECT_TRUE(foundTestFile1);
}

TEST_F(FileSystemTest, FindPathTest) {
    // Create a test file.
    std::filesystem::path file = testDir / "example.txt";
    {
        std::ofstream ofs(file);
        ofs << "Test file";
    }

    // Use findPath to locate the file.
    auto foundPath = fsManager.findPath(testDir, "example.txt");
    EXPECT_FALSE(foundPath.empty());
    EXPECT_EQ(foundPath.filename(), "example.txt");
}

TEST_F(FileSystemTest, CopyFileTest) {
    // Create a source file.
    std::filesystem::path srcFile = testDir / "src.txt";
    std::filesystem::path destFile = testDir / "dest.txt";
    {
        std::ofstream ofs(srcFile);
        ofs << "Content";
    }

    // Copy the source file to the destination.
    fsManager.copyFile(srcFile, destFile, true);
    EXPECT_TRUE(std::filesystem::exists(destFile));
}

TEST_F(FileSystemTest, RecursiveSearchAndFindTest) {
    // Create a subdirectory and file within it.
    std::filesystem::path subDir = testDir / "subdir";
    fsManager.createDirectory(subDir);
    std::filesystem::path subFile = subDir / "subfile.txt";
    {
        std::ofstream ofs(subFile);
        ofs << "Subdirectory content";
    }

    // Test recursive search.
    auto recResults = fsManager.searchFilesRecursive(testDir, "subfile.txt");
    EXPECT_FALSE(recResults.empty());
    EXPECT_EQ(recResults[0].filename(), "subfile.txt");

    // Test recursive find.
    auto foundRec = fsManager.findPathRecursive(testDir, "subfile.txt");
    EXPECT_FALSE(foundRec.empty());
    EXPECT_EQ(foundRec.filename(), "subfile.txt");
}

TEST_F(FileSystemTest, FileExistsTest) {
    // Create a file and test for existence.
    std::filesystem::path file = testDir / "exist.txt";
    {
        std::ofstream ofs(file);
        ofs << "Exists";
    }
    EXPECT_TRUE(fsManager.fileExists(file));
    EXPECT_FALSE(fsManager.fileExists(testDir / "nonexistent.txt"));
}

TEST_F(FileSystemTest, CreateDirectoryTest) {
    // Create a new directory.
    std::filesystem::path newDir = testDir / "newdir";
    fsManager.createDirectory(newDir);
    EXPECT_TRUE(std::filesystem::exists(newDir));
    EXPECT_TRUE(std::filesystem::is_directory(newDir));
}