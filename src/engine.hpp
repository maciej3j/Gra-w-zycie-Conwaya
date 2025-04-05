#pragma once

#include "cell.hpp"
#include <vector>

class Engine {
protected:
  std::size_t rows;
  std::size_t columns;
  std::vector<Cell> data;

public:
  Engine(std::size_t width, std::size_t height)
      : rows(width), columns(height), data(width * height) {}
  ~Engine() = default;
  Cell &get_cell(std::size_t row, std::size_t col);
  const Cell &get_cell(std::size_t row, std::size_t col) const;
  std::vector<Cell> neighbours(std::size_t row, std::size_t col);
  std::size_t count_alive(std::size_t row, std::size_t col);
  void step();
};
