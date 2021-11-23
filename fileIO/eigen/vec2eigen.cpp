#include <Eigen/Dense>
#include <cassert>
#include <iostream>
#include <vector>

using namespace Eigen;
using std::vector;

template <typename T>
inline VectorXd makeEigenArrayFromVectors(const vector<T> &vecvalues) {
  size_t n = vecvalues.size();
  VectorXd V(n);
  for (size_t i{0}; i != vecvalues.size(); ++i) {
    V(i) = vecvalues[i];
  }
  return V;
}

int main() {

  vector<double> values = {0.22, -0.88, 3.33, 2.43};

  VectorXd b = makeEigenArrayFromVectors(values);

  std::cout << b << "\n";
}

// g++ -std=c++11 -I /usr/include/eigen3/ vec2eigen.cpp