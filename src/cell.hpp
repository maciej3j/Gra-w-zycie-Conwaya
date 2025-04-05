
class Cell {
  bool alive;

public:
  Cell(bool is_alive = false) : alive{is_alive} {}
  bool is_alive() const { return alive; }
  void set_alive(bool is_alive) { alive = is_alive; }
};
