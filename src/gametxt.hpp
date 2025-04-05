#include "game.hpp"

class GameTxt : public Game {
public:
  GameTxt(std::size_t width, std::size_t height) : Game(width, height) {}
  void display() const override;
};
