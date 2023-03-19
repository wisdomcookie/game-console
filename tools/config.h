#ifndef CONFIG_H
#define CONFIG_H
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <filesystem>
#include "baseclass.h"
#include "macro.h"
using namespace std;

class Config : public BaseClass
{
public:
    Config();
    /**
    * @brief Config
    * @param filePath
    */
    Config(string filePath);
    /**
     * @brief Config constructor takes another config object and creates a copy
     * @param obj the object to be copied
     */
    Config(Config &obj);

    /**
     * @brief operator = takes another config object and copies its attributes
     * @param obj the object to be copied
     */
    void operator=(Config &obj);

    ~Config(); //destructor

    /**
     * @brief loadConfigs loads existing configuration from file
     */
    void load_configs();
    /**
     * @brief loadNewConfigs loads new configuration
     * @param newPath the new path
     */
    void load_configs_from(string newPath);
    /**
     * @brief updateConfigs changing the value for an exisiting configuration
     */
    void store_configs();
    /**
     * @brief storeConfigs store path and file names
     * @param filePath
     */
    void store_configs_in(string filePath);
    /**
     * @brief changeConfig changes the configuration to the specified key and value
     * @param config configuration to change to
     * @param value value to change to
     */
    void change_config(string config, string value);
    /**
     * @brief addConfig adds configuration at specified key and value
     * @param config the configuration being added
     * @param value the value being added
     */
    void add_config(string config, string value);
    /**
     * @brief get_configs getter method for the configs
     * @return the configs map
     */
    map<string, string> get_configs();
    /**
     * @brief getState getter method for the state of the object
     * @return the object's state
     */
    string get_state();
    /**
     * @brief getFilePath getter method for file path
     * @return the file path
     */
    string get_filePath();
    /**
     * @brief setFilePath sets the file path
     * @param newPath the new file path
     */
    void set_filePath(string newPath);
    /**
     * @brief getFileName
     * @return the file name
     */
    string get_fileName();
    /**
     * @brief setFileName
     * @param newName the new file name
     */
    void set_fileName(string newName);

    /**
     * @brief printConfigs prints out the map of configs
     */
    void print_configs();

private:
    /**
     * @brief state the object's state
     */
    string state;
    /**
     * @brief configs map template to store the information
     */
    map<string, string> configs;
    /**
     * @brief filePath
     */
    string filePath;
    /**
     * @brief fileName
     */
    string fileName;
    /**
     * @brief readfh
     */
    ifstream readfh;
    /**
     * @brief writefh
     */
    ofstream writefh;
};


#endif // CONFIG_H
