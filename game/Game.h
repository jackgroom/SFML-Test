//
// Created by jack- on 24/09/2022.
//

#include <vector>

#include <SFML/Graphics.hpp>
#include "../game/Circle.h"

#ifndef GAME_H
#define GAME_H

#define WIDTH   640
#define HEIGHT  480

typedef struct Game Game;
struct Game {
public:
    Game();
    Game(const Game&) = delete;
    ~Game();

    void set_isRunning(bool value);
    void beginGameLoop();

    void add_render(Circle*);
private:
    int width = WIDTH;
    int height = HEIGHT;

    sf::RenderWindow window;
    bool isRunning{};

    std::vector<Circle*> renders;
};

#endif //GAME_H
