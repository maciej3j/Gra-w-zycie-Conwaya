#pragma once

#include "cell.hpp"
#include <array>
#include <fstream>

template <std::size_t Width, std::size_t Height> class Engine {
protected:
  inline static std::size_t rows = Height;
  inline static std::size_t columns = Width;
  std::array<Cell, rows * columns> data;

public:
  Engine();
  ~Engine() = default;
  Cell &get_cell(std::size_t row, std::size_t col);
  std::array<Cell, 8> neighbours(std::size_t row, std::size_t col);
  void step();
};

template <std::size_t Width, std::size_t Height> Engine::Engine() {
  std::ifstream read_file("input.txt");
  read_file
}

template <std::size_t Width, std::size_t Height>
Cell &Engine::get_cell(std::size_t row, std::size_t col) {
  return data[row * columns + col];
}

template <std::size_t Width, std::size_t Height>
std::array<Cell, 8> Engine::neighbours(std::size_t row, std::size_t col) {
  std::array<int, 8> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
  std::array<int, 8> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
  std::array<Cell, 8> result;
  for (std::size_t i = 0; i < dx.size(); i++) {
    auto new_row = static_cast<int>(row) + dx[i];
    auto new_col = static_cast<int>(col) + dy[i];
    if (new_row >= 0 && new_row < Height && new_col >= 0 && new_col < Width) {
      result[i] = get_cell(static_cast<std::size_t>(new_row),
                           static_cast<std::size_t>(new_col));
    } else {
      result[i] = Cell();
    }
  }
  return result;
}
