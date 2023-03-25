#ifndef ROBOTS_H
#define ROBOTS_H
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <iostream>
#include "engine.h"



class Robots : public Engine
{
public:
    Robots();
    Robots(int rows, int cols);
    ~Robots();

    /**
     * @brief next_time_step advances the game state after one move
     */
    void next_time_step();

    /**
     * @brief new_level initialize the gameboard for a new level
     */
    void new_level();

    /**
     * @brief robot_get_next_pos gets the robot at (x,y)'s next position in the direction of the player
     * @param x
     * @param y
     * @param xplayer
     * @param yplayer
     * @return the next position as a int pair
     */
    std::pair<int, int> robot_get_next_pos(int x, int y, int xplayer, int yplayer);

    /**
     * @brief robot_get_next_dir gets the robot at (x,y)'s next move in the direction of the player
     * @param x
     * @param y
     * @param xplayer
     * @param yplayer
     * @return the next move as a int pair
     */
    std::pair<int, int> robot_get_next_dir(int x, int y, int xplayer, int yplayer);

    /**
     * @brief kill_robot kills the robot if there is one at (x,y)
     * @param x
     * @param y
     * @return true if killed a robot, false otherwise
     */
    bool kill_robot(int x, int y);

    /**
     * @brief add_robot adds robot to the game board
     * @param x the x-coordinate of the robot
     * @param y the y-coordinate of the robot
     */
    bool add_robot(int x, int y);
    /**
     * @brief add_player adds player to the game board
     * @param x the x-coordinate of the player
     * @param y the y-coordinate of the player
     */
    bool add_player(int x, int y);
    /**
     * @brief add_scrap adds scrap to the game board
     * @param x the x-coordinate of the scrap
     * @param y the y-coordinate of the scap
     */
    bool add_scrap(int x, int y);

    /**
     * @brief player_do mvoes object based on direction
     * @param c the cahracter of direction
     */
    void player_do();
    bool valid_move(char input);
};

#endif // ROBOTS_H
