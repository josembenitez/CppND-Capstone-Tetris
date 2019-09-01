
#ifndef GAME_H
#define GAME_H


#include <chrono>
#include <random>

#include "controller.h"
#include "playfield.h"
#include "renderer.h"
#include "tetromino.h"


class game
{
public:
    game(std::size_t well_width, std::size_t well_height);
    ~game();

    void run(const controller &cntrllr, renderer &rndrr, std::size_t fps);

private:
    static constexpr std::size_t lines_to_change_level = 10;
    static constexpr std::size_t max_level = 10;
    static constexpr std::size_t delay_interval = 50;

    std::size_t delay;
    std::size_t score;
    std::size_t cleared_lines;
    std::size_t level;
    playfield pf;
    int x;
    int y;
    tetromino *current;
    std::chrono::time_point<std::chrono::system_clock> last_update;

    std::random_device dev;
    std::mt19937 engine;
    std::uniform_int_distribution<int> random_tetromino;

    std::size_t drop_down();
    void get_next_tetromino();
    bool move_down();
    bool move_left();
    bool move_right();
    bool playfield_is_filled_up() const;
    bool rotate_clockwise();
    bool rotate_counterclockwise();
    bool update(input inpt);
    void update_delay();
    void update_level(std::size_t lines);
    void update_score(std::size_t cleared_lines, std::size_t dropped_lines);
};


#endif  /* GAME_H */
