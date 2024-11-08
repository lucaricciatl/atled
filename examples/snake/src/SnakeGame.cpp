// SnakeGame.cpp
#include "SnakeGame.hpp"


SnakeGame::SnakeGame()
    : gameOver(false), direction(RIGHT) {
    // Default constructor - no managers assigned yet
}

SnakeGame::SnakeGame(std::shared_ptr<input::InputManager> input, std::shared_ptr<graphics::IGraphicManager> graphics)
    : inputManager(input), graphicsManager(graphics), gameOver(false), direction(RIGHT) {
    // Constructor with managers
}

void SnakeGame::SetManagers(std::shared_ptr<input::InputManager> input, std::shared_ptr<graphics::IGraphicManager> graphics) {
    inputManager = input;
    graphicsManager = graphics;
}

void SnakeGame::Init() {
    snake.push_back({5, 5});
    GenerateFood();
}

void SnakeGame::Update() {
    //ProcessInput();
    MoveSnake();
    if (CheckCollision()) {
        gameOver = true;
    }
}

void SnakeGame::Render() {

    // Draw snake
    for (const auto& segment : snake) {
        Coordinates2D upperLeft{ static_cast<float>(segment.x * 10), static_cast<float>(segment.y * 10) };
        Coordinates2D bottomRight{ static_cast<float>((segment.x + 1) * 10), static_cast<float>((segment.y + 1) * 10) };
        auto rect = std::make_shared<graphics::Rectangle>(upperLeft, bottomRight);
        rect->SetColor(Color(255, 255, 255, 100));
        graphicsManager->AddRectangle(0, rect);      
    }

    // Draw food
    Coordinates2D foodUpperLeft{ static_cast<float>(food.x * 10), static_cast<float>(food.y * 10) };
    Coordinates2D foodBottomRight{ static_cast<float>((food.x + 1) * 10), static_cast<float>((food.y + 1) * 10) };
    auto rect = std::make_shared<graphics::Rectangle>(foodUpperLeft, foodBottomRight);

    graphicsManager->AddRectangle(0, rect);
    rect->SetColor(Color(255, 0, 0, 100));


}


bool SnakeGame::IsGameOver() const {
    return gameOver;
}

void SnakeGame::GenerateFood() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 19); // Assuming a 20x20 grid
    food = {dist(gen), dist(gen)};
}

void SnakeGame::ProcessInput() {
    if (inputManager->IsKeyPressed(KEY_UP) && direction != DOWN) direction = UP;
    if (inputManager->IsKeyPressed(KEY_DOWN) && direction != UP) direction = DOWN;
    if (inputManager->IsKeyPressed(KEY_LEFT) && direction != RIGHT) direction = LEFT;
    if (inputManager->IsKeyPressed(KEY_RIGHT) && direction != LEFT) direction = RIGHT;
}

void SnakeGame::MoveSnake() {
    Position newHead = snake.front();
    switch (direction) {
        case UP: newHead.y--; break;
        case DOWN: newHead.y++; break;
        case LEFT: newHead.x--; break;
        case RIGHT: newHead.x++; break;
    }

    // Check if food is eaten
    if (newHead.x == food.x && newHead.y == food.y) {
        snake.push_front(newHead);
        GenerateFood();
    } else {
        snake.push_front(newHead);
        snake.pop_back(); // Move the snake forward
    }
}

bool SnakeGame::CheckCollision() const {
    const Position& head = snake.front();
    if (head.x < 0 || head.x >= 20 || head.y < 0 || head.y >= 20) return true;
    for (size_t i = 1; i < snake.size(); ++i) {
        if (snake[i].x == head.x && snake[i].y == head.y) return true;
    }
    return false;
}
