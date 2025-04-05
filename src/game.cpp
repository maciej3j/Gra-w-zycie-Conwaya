#include <thread>
#include <vector>

#include "game.hpp"

void Game::load_from_file(std::vector<std::pair<std::size_t, std::size_t>> xy,
                          std::size_t alive_at_start) {
  for (std::size_t i{0}; i < xy.size(); i++) {
    this->get_cell(xy[i].first, xy[i].second).set_alive(true);
  }
}

void Game::run() {
  using namespace std::chrono_literals;
  this->step();
  std::this_thread::sleep_for(150ms);
}
