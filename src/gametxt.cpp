#include "gametxt.hpp"
#include <iostream>

void GameTxt::display() const {
  std::cout << "\033[2J\033[H";
  for (std::size_t r = 0; r < rows; ++r) {
    for (std::size_t c = 0; c < columns; ++c) {
      if (this->get_cell(r, c).is_alive()) {
        std::cout << "X ";

      } else {
        std::cout << ". ";
      }
    }
    std::cout << "\n";
  }
}
