#include <iostream>
#include "gtest/gtest.h"
#include "../tools/log.h"
#include "../tools/config.h"

// The fixture for testing class Foo.
class FooTest : public ::testing::Test {
protected:
    // You can remove any or all of the following functions if its body
    // is empty.
    FooTest() {
        // You can do set-up work for each test here.
    }
    virtual ~FooTest() {
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
    /** replace with your own **/
    Config s1;
    Config s2;
};

TEST(general, TESTSIMPLE) {
    /** replace with your own **/
    Config s1;
    Config s2("exampleConfigFile.txt");
    ASSERT_EQ(s1.get_fileName(), s2.get_fileName()) << s1.get_fileName()
                                                    << " and "
                                                    << s2.get_fileName()
                                                    << " should match!";
}

TEST(general, TESTSTORE){
    Config c1("test.txt");
    c1.add_config("type", "orange");
    //c1.add_config("wood", "knocked");
    c1.store_configs();
    fstream fh;
    string configstr = "";
    fh.open("test.txt", ios::in); //opens file
    while(fh){ //reads file
        string line;
        getline(fh, line);
        string tempConfig = line.substr(0, line.find(":"));
        string tempValue = line.substr(line.find(":")+1, line.length());

        string temp = tempConfig + ":" + tempValue;
        configstr += temp;
    }
    ASSERT_EQ(configstr, "type:orange:") << "Configs should match";
}

TEST(general, TESTLOAD){
    Config c1("test2.txt");

    fstream fh;
    fh.open("test2.txt");
    fh << "wood:knocked" << "\n";
    fh.close();
    c1.load_configs();

    map<string, string> configmap = c1.get_configs();
    string configstr = "";
    for (auto item = configmap.begin(); item != configmap.end(); item++){ //loops through configs
        string temp = "";
        configstr = item->first + ":" + item->second +"\n"; //temp is the key then the value
    }
    ASSERT_EQ(configstr, "wood:knocked\n") << "Loaded configs should match";
}
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

TEST(general, TESTSIMPLE1) {
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
    c1.flush_log(); //flush log
    fstream fh;
    fh.open("test.txt", ios::in); //opens file
    getline(fh, line);
    ASSERT_EQ(line, "hello world") << "Logs should match";
}

TEST(general, TESTEXISTING){
    Log l1("C:/Users/nhant/directory.txt");
    l1.close_log();
    l1.open_log_new();
    l1 << "hello";
    l1.close_log();
    fstream fh;
    string line;
    fh.open("C:/Users/nhant/directory.txt", ios::in);
    getline(fh, line);
    ASSERT_EQ(line, "hello") << "Logs should match";
}
//TEST(general, TESTEMPTY){
//    Log c1("test2.txt");
//    string line;
//    fstream fh;
//    c1.open_log_new(); //calls open log empty
//    fh.open("test2.txt", std::ios::trunc);
//    while(fh){ //reads file
//        getline(fh, line);
//    }
//    ASSERT_EQ(c1.get_state(), "open") << "States should match";
//    ASSERT_EQ(line, "") << "Logs should match";
//}


int main(int argc, char **argv) {
    Log test("pathtest.txt");
    std::cout << test.get_filePath();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
