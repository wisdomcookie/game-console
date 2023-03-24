#ifndef ENGINE_H
#define ENGINE_H
#define DEFAULTROWS 20
#define DEFAULTCOLS 20
#include <iostream>


class Engine
{
public:
    Engine(); //might not need default constructor, still trying to figure out using in child classes
    Engine(int rows, int cols);
    ~Engine();

    bool remove_char_at(int x, int y);
    bool insert_char_at(char c, int x, int y);
    bool move_char(int x, int y, int dx, int dy);
    bool move_char_to(int x, int y, int newx, int newy);
    char get_char_at(int x, int y);
    void clear_gameboard();
    bool valid_gameboard(int x, int y);
    void print_gameboard();
    std::string gameboard_string();

protected:

    char **gameboard;
    int rows;
    int cols;

};

#endif // ENGINE_H
