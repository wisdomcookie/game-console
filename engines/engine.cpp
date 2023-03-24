#include "engine.h"



Engine::Engine(): rows(DEFAULTROWS), cols(DEFAULTCOLS){

    gameboard = new char*[rows]; //allocation
    for(int i = 0; i < rows; i+=1){
        gameboard[i] = new char[cols];
    }

    for(int i = 0; i < rows; i+=1){ //loops through rows
        for(int j = 0; j < cols; j+=1){ //loops through cols
            gameboard[i][j] = '_'; //creates an empty gameboard
        }
    }
}

Engine::Engine(int rows, int cols): rows(rows), cols(cols){

    gameboard = new char*[rows]; //allocation
    for(int i = 0; i < rows; i+=1){
        gameboard[i] = new char[cols];
    }

    for(int i = 0; i < rows; i+=1){ //loops through rows
        for(int j = 0; j < cols; j+=1){ //loops through cols
            gameboard[i][j] = '_'; //creates an empty gameboard
        }
    }
}


Engine::~Engine(){

    for(int i = rows - 1; i >= 0; i-=1){
        delete[] gameboard[i]; //deallocates each row
    }
    delete[] gameboard; //deallocates gameboard
}

bool Engine::remove_char_at(int x, int y) {
    if(!valid_gameboard(x, y) || gameboard[x][y] == '_')
        return false; //return false if already empty

    gameboard[x][y] = '_'; //make spot empty
    return true; //return true when removed
}

bool Engine::insert_char_at(char c, int x, int y){
    if(!valid_gameboard(x, y))
        return false;
    gameboard[x][y] = c; // inserts character at position
    return true;
}

char Engine::get_char_at(int x, int y) {
    if(!valid_gameboard(x, y))
        return 0;
    return gameboard[x][y]; //return character at specified location
}

bool Engine::move_char(int x, int y, int dx, int dy){
    if(!valid_gameboard(x, y) || !valid_gameboard(x + dx, y + dy))
        return false;
    insert_char_at(get_char_at(x, y), x + dx, y + dy);
    remove_char_at(x, y);
    return true;
}

bool Engine::move_char_to(int x, int y, int xnew, int ynew){
    if(!valid_gameboard(x, y) || !valid_gameboard(xnew, ynew))
        return false;
    insert_char_at(get_char_at(x, y), xnew, ynew);
    remove_char_at(x, y);
    return true;
}

void Engine::clear_gameboard(){
    for(int i = 0; i < rows; i+=1){ //loops through rows
        for(int j = 0; j < cols; j+=1){ //loops through cols
            gameboard[i][j] = '_'; //creates an empty gameboard
        }
    }
}

bool Engine::valid_gameboard(int x, int y){
    if(!gameboard || x < 0 || x >= rows || y < 0 || y >= cols)
        return false; // checks for null gameboard and x and y out of bounds
    return true;
}
