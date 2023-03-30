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

    /**
     * @brief get_playerpos gets the player position
     * @return player position
     */
    std::pair<int, int> get_playerpos();

    int get_points();

    state get_gamestate();

    std::string get_gamestate_string();

    /**
     * @brief set_player_input Sets the player input for the next move to c
     * @param c
     */
    void set_player_input(char c);

    /**
     * @brief set_robots_per_level Sets the amount of robots to be added with each level
     */
    void set_robots_per_level();

private:

    /**
     * @brief gamestate the state of the game
     */
    state gamestate;
    /**
     * @brief points the points of the player
     */
    int points;
    /**
     * @brief bonuspoints the bonus points gained in this level from wait kills
     */
    int bonuspoints;
    /**
     * @brief playerpos the player position
     */
    std::pair<int, int> playerpos;
    /**
     * @brief playerInput the player input for the next move
     */
    char playerInput;

    /**
     * @brief robotcount the number of current robots
     */
    int robotcount;
    /**
     * @brief robotsperlevel the number of robots to be added per additional level
     */
    int robotsperlevel;
    /**
     * @brief maxrobots the max number of robots for the current level
     */
    int maxrobots;
    /**
     * @brief currentlevel the current level
     */
    int currentlevel;
    /**
     * @brief robots set that contains the robots
     */
    std::set<std::pair<int, int>> robots;

    /**
     * @brief scrapcount the number of current scraps
     */
    int scrapcount;

    /**
     * @brief scrap set that contains the scraps
     */
    std::set<std::pair<int, int>> scrap;
};

#endif // ROBOTS_H
