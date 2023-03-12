#ifndef DOTH_H
#define DOTH_H

#include <fstream>
#include <string>
#include <filesystem>
#include "baseclass.h"
#include "macro.h"
using namespace std;
class Log : public BaseClass
{

public:

    /**
    * @brief Log default constructor that opens file
    */
    Log();

    /**
     * @brief Log parameritized constructor
     * @param fileName the name of the file
     */
    Log(std::string fileName);

    /**
     * @brief Log_copy copy constructor
     * @param obj log object
     */
    Log(Log &obj);

    /**
     * @brief operator = copy's assignment
     * @param obj log object
     */
    void operator=(Log &obj);

    ~Log();// destructor

    /**
     * @brief operator <<
     * @param str incoming string
     * @return the overloaded operator as a reference
     */
    Log& operator<<(const std::string str);

    /**
     * @brief operator <<
     * @param num incoming integer
     * @return the overloaded operator as a reference
     */

    Log& operator<<(const int num);

    /**
     * @brief operator <<
     * @param num incoming double
     * @return the overloaded operator as a reference
     */
    Log& operator<<(const double num);

    /**
     * @brief openLogEmpty opens file as an empty file
     */
    void open_log_empty();

    /**
     * @brief openLogAppend appends additional lines to the end of an existing file
     */
    void open_log_append();

    /**
     * @brief closeLog
     */
    void close_log();

    /**
     * @brief flushLog
     */
    void flush_log();

    /**
     * @brief getState getter method for state
     * @return state
     */
    std::string get_state();

    /**
     * @brief getFileName getter method for file name
     * @return the file name
     */
    std::string get_fileName();

    /**
     * @brief getFilePath getter method for file path
     * @return the file path
     */
    std::string get_filePath();

private:
    /**
     * @brief fileName the file name
     */
    string fileName;
    /**
     * @brief state the state
     */
    string state;
    /**
     * @brief filePath the file path
     */
    string filePath;
    /**
     * @brief fh the file handler
     */
    std::ofstream fh;

};

#endif // DOTH_H
