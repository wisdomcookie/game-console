#include <iostream>
#include "gtest/gtest.h"
#include "../tools/log.h"
// The fixture for testing class Log.
class LogTest : public ::testing::Test {
protected:
    // You can remove any or all of the following functions if its body
    // is empty.
    LogTest() {
        // You can do set-up work for each test here.
    }
    virtual ~LogTest() {
        // You can do clean-up work that doesn’t throw exceptions here.
    }
    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:
    virtual void SetUp() {
        // Code here will be called immediately after the constructor (right
        // before each test).
    }
    virtual void TearDown() {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }
    // Objects declared here can be used by all tests in the test case for Foo.
    Log s1;
    Log s2;
};

TEST(general, TESTSIMPLE) {
    Log s1; //first log object
    Log s2("exampleLogFile.txt"); //second log object
    ASSERT_EQ(s1.get_fileName(), s2.get_fileName()) << s1.get_fileName()
                                                    << " and "
                                                    << s2.get_fileName()
                                                    << " should match!";
}

TEST(general, TESTAPPEND){
    Log c1("test.txt");
    string line;
    c1 << ("hello world\n"); //appends string to log
    c1.open_log_append(); //calls open log append
    fstream fh;
    c1.flush_log(); //flush log
    fh.open("test.txt", ios::in); //opens file
    getline(fh, line);
    ASSERT_EQ(line, "hello world") << "Logs should match";
}

TEST(general, TESTEMPTY){
    Log c1("test2.txt");
    string line;
    fstream fh;
    c1.open_log_empty(); //calls open log empty
    fh.open("test2.txt", std::ios::trunc);
    while(fh){ //reads file
        getline(fh, line);
    }
    ASSERT_EQ(c1.get_state(), "open") << "States should match";
    ASSERT_EQ(line, "") << "Logs should match";
}

TEST(general, TESTFIXTURE) {
    Log s1; //log object 1
    Log s2(""); //log object 2
    ASSERT_EQ(s1.get_filePath(), s2.get_filePath()) << "These file paths should match!";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
