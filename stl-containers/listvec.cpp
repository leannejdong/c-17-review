#include <chrono>
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::steady_clock;
using std::chrono::system_clock;
#include <iostream>
#include <list>
#include <vector>
#include <random>
using std::list;
using std::vector;


void BuildVector(const int &size, vector<int> &v);
void BuildList(const int &size, list<int> &l);

template <typename Func> long long TimeFunc(Func f) {
  auto begin = steady_clock::now();
  f();
  auto end = steady_clock::now();

  return duration_cast<milliseconds>(end - begin).count();
}

int rand11() {
  static std::mt19937 engine;
  static std::uniform_int_distribution<int> dist;
  return dist(engine);
}

void BuildVector(const int &size, vector<int> &v) {
  for (int i = 0; i < size; i++) {
    int r = static_cast<int> (rand11());
    bool inserted = false;
    for (auto it = begin(v); it != end(v); it++) {
      if (*it > r) {
        v.insert(it, r);
        inserted = true;
        break;
      }
    }
    if (!inserted)
      v.push_back(r);
  }
}

void BuildList(const int &size, list<int> &l) {
  // list
  for (int i = 0; i < size; i++) {
    int r = static_cast<int> (rand11());
    bool inserted = false;
    for (auto it = begin(l); it != end(l); it++) {
      if (*it > r) {
        l.insert(it, r);
        inserted = true;
        break;
      }
    }
    if (!inserted)
      l.push_back(r);
  }
}

int main() {
  int const size = 10000;

  vector<int> v;
  v.push_back(0);

  list<int> l;
  l.push_back(0);

  auto vectormilliseconds = TimeFunc([&]() { BuildVector(size, v); });
  auto listmilliseconds = TimeFunc([&]() { BuildList(size, l); });
  std::cout << vectormilliseconds << std::endl;
  std::cout << listmilliseconds << std::endl;
}