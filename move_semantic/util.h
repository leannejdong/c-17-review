#include <chrono>
#include <random>
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::steady_clock;

auto rand11() -> int {
  static std::mt19937 engine;
  static std::uniform_int_distribution<int> dist;
  return dist(engine);
}

template <typename T>
long long Timer(T f) {
  auto begin = steady_clock::now();
  f();
  auto end = steady_clock::now();
  return duration_cast<milliseconds>(end - begin).count();
}