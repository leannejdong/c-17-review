#include "Resource.h"
#include "util.h"
#include <iostream>

#include <string>
using std::string;

#include <list>
#include <vector>
using std::cerr;
using std::list;
using std::vector;

#include <algorithm>

template <typename T> void exercise(int size, string commoname) {
  T v;
  typename T::value_type res0("starting entry");
  v.push_back(res0);
  for (int i{0}; i < size; ++i) {
    int r = static_cast<int>(rand11());
    string s;
    int ss = r % 100;
    s.reserve(ss);
    std::generate_n(std::back_inserter(s), ss,
                    [ss]() { return (char)('!' + ss / 2); });
    typename T::value_type res(s);
    bool inserted = false;
    for (auto it = begin(v); it != end(v); it++) {
      if (*it > res) {
        v.insert(it, res);
        inserted = true;
        break;
      }
    }
    if (!inserted)
      v.push_back(res);
  }
  auto it = max_element(v.begin(), v.end());
  typename T::value_type maxV = *it;
  it = min_element(begin(v), end(v));
  typename T::value_type minV = *it;

  bool sorted = is_sorted(begin(v), end(v));
}

int main() {
  const int size = 1000;
  auto vectormilliseconds =
      Timer([&]() { exercise<vector<Resource>>(size, "vector"); });
  auto listmilliseconds =
      Timer([&]() { exercise<list<Resource>>(size, "list"); });

  cerr << "Time in milliseconds for vector: " << vectormilliseconds << "\n";
  cerr << "Time in milliseconds for list: " << listmilliseconds << "\n";
}

// https://compiler-explorer.com/z/9W3bGG8YW
