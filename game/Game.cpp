//
// Created by jack- on 24/09/2022.
//
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Game.h"

// ---------------------------------------------------------------------------------------------------------------------

Game::Game()
{
    this->window.create(sf::VideoMode(this->width, this->height), "SFML Test");
    this->isRunning = false;
}

Game::~Game() = default;

// ---------------------------------------------------------------------------------------------------------------------

void Game::set_isRunning(bool value)
{
    this->isRunning = value;
}

void Game::add_render(Circle* newRender)
{
    std::cout << "New render added" << std::endl;
    this->renders.push_back(newRender);
}

// ---------------------------------------------------------------------------------------------------------------------

void Game::beginGameLoop()
{
    this->isRunning = true;
    while (this->window.isOpen() && this->isRunning)
    {
        sf::Event event{};
        while (this->window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    this->set_isRunning(false);
                    break;
            }
        }

        this->window.clear();

        for (Circle* render : this->renders) {
            render->update();
            this->window.draw(render->render());
        }

        this->window.display();
    }
}

// ---------------------------------------------------------------------------------------------------------------------


