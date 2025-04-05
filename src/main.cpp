#include "gametxt.hpp"
#include <fstream>
#include <iostream>

int main() {
  std::ifstream ifile("input.txt");
  if (!ifile) {
    std::cerr << "Nie udało się wczytać pliku z danymi!\n";
  }
  std::size_t rows, columns, alive_at_start;
  ifile >> rows >> columns >> alive_at_start;
  std::vector<std::pair<std::size_t, std::size_t>> xy(alive_at_start);
  for (std::size_t i{0}; i < alive_at_start; ++i) {
    ifile >> xy[i].first >> xy[i].second;
  }

  GameTxt game(rows, columns);
  game.load_from_file(xy, alive_at_start);

  while (true) {
    game.run();
    game.display();
  }
}
