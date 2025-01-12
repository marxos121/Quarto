#pragma once

#include "BaseState.h"
#include "board.h"

#include <SFML/Graphics.hpp>

#include <array>
#include <memory>

class Player;

// Stan gry definiujący właściwą rozgrywkę
class StatePlay : public BaseState {
    static const int CELL_SIZE_LARGE = 100; // Rozmiar komórki dużej planszy
    static const int GRID_SIZE_LARGE = 4;   // Rozmiar dużej planszy (GRID_SIZE_LARGE x GRID_SIZE_LARGE)

    static const int CELL_SIZE_PAWNS = 50;  // Rozmiar komórki małej planszy (2 razy mniejszy)
    static const int GRID_SIZE_PAWNS_ROWS = 2; // Liczba wierszy małej planszy
    static const int GRID_SIZE_PAWNS_COLS = 8; // Liczba kolumn małej planszy

    public:
        StatePlay(sf::RenderWindow* window = nullptr);
        void processInput(const sf::Event&) final;
        void update() final;
        void draw() const final;

    private:
        void initializeGrids();

        short m_currentPlayer = 0;
        bool m_stagePlace = 0;          // W przypadku ruchów gracza ludzkiego,
                                        // Musimy wiedzieć, czy aktualnie legalnym ruchem jest
                                        // Umieszczenie pionka, czy wybranie kolejnego pionka

        Board m_board;
        std::shared_ptr<Player> m_players[2];
        sf::RectangleShape grid[GRID_SIZE_LARGE][GRID_SIZE_LARGE];
        sf::RectangleShape pawns[GRID_SIZE_PAWNS_ROWS * GRID_SIZE_PAWNS_COLS]; 
};