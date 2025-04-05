#include "engine.hpp"
#include <array>

Cell &Engine::get_cell(std::size_t row, std::size_t col) {
  return data[row * columns + col];
}

const Cell &Engine::get_cell(std::size_t row, std::size_t col) const {
  return data[row * columns + col];
}

std::vector<Cell> Engine::neighbours(std::size_t row, std::size_t col) {
  std::array<int, 8> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
  std::array<int, 8> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
  std::vector<Cell> result(8);
  for (std::size_t i = 0; i < dx.size(); i++) {
    auto new_row = static_cast<int>(row) + dx[i];
    auto new_col = static_cast<int>(col) + dy[i];
    if (new_row >= 0 && new_row < rows && new_col >= 0 && new_col < columns) {
      result[i] = get_cell(static_cast<std::size_t>(new_row),
                           static_cast<std::size_t>(new_col));
    } else {
      result[i] = Cell();
    }
  }
  return result;
}
std::size_t Engine::count_alive(std::size_t row, std::size_t col) {
  auto arr = neighbours(row, col);
  std::size_t count{0};
  for (const auto &cell : arr) {
    if (cell.is_alive()) {
      count++;
    }
  }
  return count;
}

void Engine::step() {
  std::vector<Cell> next_data(rows * columns);
  for (std::size_t r = 0; r < rows; ++r) {
    for (std::size_t h = 0; h < columns; h++) {
      auto cell_neighbours = neighbours(r, h);
      auto neighbours_count = count_alive(r, h);
      if (data[r * columns + h].is_alive()) {
        if (neighbours_count < 2 || neighbours_count > 3) {
          next_data[r * columns + h] = Cell();
        } else {
          next_data[r * columns + h] = Cell(true);
        }
      } else {
        if (neighbours_count == 3) {
          next_data[r * columns + h] = Cell(true);
        }
      }
    }
  }
  data = next_data;
}
