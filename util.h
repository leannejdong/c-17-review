#include <random>

int rand11() {
  static std::mt19937 engine;
  static std::uniform_int_distribution<int> dist;
  return dist(engine);
}



