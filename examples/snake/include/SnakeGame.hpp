// SnakeGame.hpp
#pragma once
#include "InputManager.hpp"
#include "GraphicsManager.hpp"
#include <deque>
#include <memory>
#include <random>

class SnakeGame {
public:
    SnakeGame();  // Default constructor
    SnakeGame(std::shared_ptr<input::InputManager> input, std::shared_ptr<graphics::IGraphicManager> graphics); // Constructor with managers

    void SetManagers(std::shared_ptr<input::InputManager> input, std::shared_ptr<graphics::IGraphicManager> graphics);
    void Init();
    void Update();
    void Render();
    bool IsGameOver() const;

private:
    enum Direction { UP, DOWN, LEFT, RIGHT };
    struct Position { int x, y; };

    std::shared_ptr<input::InputManager> inputManager;         // Use shared_ptr for shared ownership
    std::shared_ptr<graphics::IGraphicManager> graphicsManager; // Use shared_ptr for shared ownership
    std::deque<Position> snake;
    Position food;
    Direction direction;
    bool gameOver;

    void GenerateFood();
    void ProcessInput();
    void MoveSnake();
    bool CheckCollision() const;
};