#include "config.h"

Config::Config(): state("start"), fileName("exampleConfigFile.txt"){
    filesystem::path thisPath = filesystem::current_path();
    filePath = thisPath.generic_string() + "/" + fileName;
    //SHOW_WHERE;
}
Config::Config(string fileName): state("start"), fileName(fileName){
    filesystem::path thisPath = filesystem::current_path();
    filePath = thisPath.generic_string() + "/" + fileName;

    //SHOW_WHERE;
}

Config::Config(Config &obj){
    state = obj.state;
    configs = obj.configs;
    filePath = obj.filePath;
    fileName = obj.fileName;
    //SHOW_WHERE;
}

void Config::operator =(Config &obj){
    state = obj.state;
    configs = obj.configs;
    filePath = obj.filePath;
    fileName = obj.fileName;

}


Config::~Config(){
    state = "store"; //state set to store
    store_configs();
}

void Config::load_configs(){
    configs.clear(); //clears existing map data
    try {
        readfh.open(filePath, ios::in); //opens file
        while(readfh){ //reads file
            string line;
            getline(readfh, line);
            string tempConfig = line.substr(0, line.find(":"));
            string tempValue = line.substr(line.find(":")+1, line.length());
            configs[tempConfig] = tempValue; //stores key and value in the map
        }
        readfh.close(); //closes file
    } catch (runtime_error) {
        "File cannot open"; //exception if file is not opened
    }
}

void Config::load_configs_from(string newPath){
    configs.clear(); //clears existing map data
    try {
        readfh.open(newPath, ios::in);
        string line;
        while(getline(readfh, line)) { //read the file to store key and value in map
            size_t separator = line.find(':');
            string key = line.substr(0, separator);
            string value = line.substr(separator + 1);
            configs[key] = value; //store key and value in map
            readfh.close(); //close file
        }

        readfh.close(); //closes file
    } catch (runtime_error) {
        "File cannot open"; //exception if file is not opened
    }
}

void Config::store_configs(){
    try {
        writefh.open(filePath, ios::out | ios::trunc); //opens file through file path
        for (auto item = configs.begin(); item != configs.end(); item++){ //loops through configs
            string temp = "";
            temp = item->first + ":" + item->second +"\n"; //temp is the key then the value
            writefh << temp; //writes into file
        }
        writefh.close(); //close file
    } catch (runtime_error) {
        "File cannot open";
    }
}

void Config::store_configs_in(string newPath){
    writefh.open(newPath, ios::out | ios::trunc);
    for (auto item = configs.begin(); item != configs.end(); item++){ //loops through configs
        string temp = "";
        temp = item->first + ":" + item->second +"\n"; //temp is the key then the value
        writefh << temp; //writes into file
    }
    writefh.close(); //close file
}

void Config::change_config(string config, string value){
    try {
        if(configs.contains(config)){ //checks if the map contains specified config
            configs[config] = value; //changes config to specified value
        }
    } catch (...) {
        "Invalid Config";
    }
}

void Config::add_config(string config, string value){
    configs[config] = value; //adds config at specificed key and value
}

void Config::print_configs(){
    for (auto item = configs.begin(); item != configs.end(); item++){ //loops through configs
        string temp = "";
        temp = item->first + ":" + item->second +"\n"; //temp is the key then the value
        std::cout << temp; //writes into file
    }
}

map<string, string> Config::get_configs(){
    return configs;
}

string Config::get_state(){
    return state;
}

string Config::get_filePath(){
    return filePath;
}

void Config::set_filePath(string newPath){
    filePath = newPath; //sets the file path as the specified new path
}

string Config::get_fileName(){
    return fileName;
}

void Config::set_fileName(string newName){
    fileName = newName; //sets the file name as the specified new file name
}
