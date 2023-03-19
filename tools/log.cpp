#include "log.h"


Log::Log(): state("open"), fileName("exampleLogFile.txt"), filePath(filesystem::current_path().generic_string() + "/exampleLogFile.txt") {
    fh.open(filePath, std::ofstream::out | std::ofstream::app ); //file handler is opened

    //SHOW_WHERE;
}

Log::Log(std::string filePath): state("open"){
    if(filePath.find("/\\") == -1){ // just file name was specified, assuming file is in same directory
        this->filePath = filesystem::current_path().generic_string() + filePath;
        fileName = filePath;
    }
    else{
        this->filePath = filePath;
        fileName = filePath.substr(filePath.find_last_of("/\\")+1);
    }

    fh.open(filePath, std::ofstream::out | std::ofstream::app); //file handler is opened with given file path
    //SHOW_WHERE;
}

Log::Log(Log &obj) {
    state = obj.state;
    fileName = obj.fileName;
    filePath = obj.filePath;
    //SHOW_WHERE;
}

void Log::operator=(Log &obj) {
    state = obj.state;
    fileName = obj.fileName;
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

void Log::open_log() {
    try {

        fh.open(filePath, std::ios::out | std::ios::app);
        state = "open"; //set state as open

    } catch (runtime_error) {
        "Failed to open file";
    }
}

void Log::open_log_new() {
    try {

        fh.open(filePath, std::ios::out | std::ios::trunc);
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
    return filePath; //returns path as a string
}
