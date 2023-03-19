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

    Log();

    /**
     * @brief Log opens log with a specific file to write to, creating new file if no file exists
     * @param fileName
     */
    Log(std::string filePath);

    /**
     * @brief Log copy constructor
     * @param obj
     */
    Log(Log &obj);

    /**
     * @brief operator = copy by assignment operator
     * @param obj
     */
    void operator=(Log &obj);

    ~Log();

    /**
     * @brief operator << writes string to log file
     * @param str incoming string
     * @return this object as a reference
     */
    Log& operator<<(const std::string str);

    /**
     * @brief operator << writes int to log file
     * @param num incoming integer
     * @return this object as a reference
     */

    Log& operator<<(const int num);

    /**
     * @brief operator << writes double to log file
     * @param num incoming double
     * @return this object as a reference
     */
    Log& operator<<(const double num);

    /**
     * @brief open_log opens the log file
     */
    void open_log();

    /**
     * @brief open_log_new opens the log file as an empty file
     */
    void open_log_new();

    /**
     * @brief close_log
     */
    void close_log();

    /**
     * @brief flush_log
     */
    void flush_log();

    std::string get_state();

    std::string get_fileName();

    std::string get_filePath();

private:
    /**
     * @brief state the state
     */
    string state;
    /**
     * @brief fileName the name of the log file
     */
    string fileName;
    /**
     * @brief filePath full path of the log file
     */
    string filePath;
    /**
     * @brief fh the file handler
     */
    std::ofstream fh;

};

#endif // DOTH_H
