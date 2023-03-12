#include "log.h"


Log::Log() {
    fh.open("./exampleLogFile.txt", std::ofstream::out | std::ofstream::app ); //file handler is opened
    //SHOW_WHERE;
}

Log::Log(std::string fileName): filePath(fileName), state("open") {
    fh.open(fileName, std::ofstream::out | std::ofstream::app); //file handler is opened with given file name
    //SHOW_WHERE;
}

Log::Log(Log &obj) {
    fileName = obj.fileName;
    state = obj.state;
    filePath = obj.filePath;
    //SHOW_WHERE;
}

void Log::operator=(Log &obj) {
    fileName = obj.fileName;
    state = obj.state;
    filePath = obj.filePath;
    //SHOW_WHERE;
}

Log::~Log() {
    fh.close(); //file handler is closed
    state = "closed"; //set state as closed
}

Log& Log::operator<<(const std::string num) {
    try {
        fh << num; //processes the incoming string
    } catch(runtime_error) {
        "File is not open";
    }
    return *this; //returns itself as a reference
}

Log& Log::operator<<(const int num) {
    try {
        fh << num; //processes the incoming integer
    }
    catch (runtime_error) {
        "File is not open";
    }
    return *this; //returns itself as a reference
}

Log& Log::operator<<(const double num) {
    try {
        fh << num; //processes the incoming double
    }
    catch(runtime_error) {
        "File is not open";
    }
    return *this; //returns itself as a reference
}
