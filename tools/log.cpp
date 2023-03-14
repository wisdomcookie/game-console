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

void Log::open_log_empty() {
    try {

        fh.open(fileName, std::ios::trunc);
        state = "open"; //set state as open

    } catch (runtime_error) {
        "Failed to open file";
    }
}

void Log::open_log_append() {
    try {

        fh.open(fileName, std::ios::out | std::ios::app);
        state = "open"; //set state as open

    } catch (runtime_error) {
        "Failed to open file";
    }
}

void Log::close_log() {
    fh.close();
    state = "closed"; //set state as closed
}

void Log::flush_log() {
    fh.flush();
    state = "flushed"; //set state as flushed
}

string Log::get_state(){
    return state;
}

string Log::get_fileName(){
    return fileName;
}

string Log::get_filePath(){
    filesystem::path thisPath = filesystem::current_path();
    string patstring = thisPath.generic_string();
    return patstring; //returns path as a string
}
