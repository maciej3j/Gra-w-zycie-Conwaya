#include <vector>

class GameInterface {
public:
  virtual void
  load_from_file(std::vector<std::pair<std::size_t, std::size_t>> xy,
                 std::size_t alive_at_start) = 0;
  virtual void run() = 0;
  virtual void display() const = 0;
  virtual ~GameInterface() = default;
};
