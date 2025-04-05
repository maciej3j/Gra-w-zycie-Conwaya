#include "engine.hpp"
#include "game_interface.hpp"

class Game : public Engine, public GameInterface {
public:
  Game(std::size_t width, std::size_t height) : Engine(width, height) {}
  void load_from_file(std::vector<std::pair<std::size_t, std::size_t>> xy,
                      std::size_t alive_at_start) override;
  void run() override;
};
