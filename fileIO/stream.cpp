#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <optional>

using std::vector;
using std::string;
using std::ifstream;

inline std::optional<string> LoadFile(const std::string& file_path)
{
    ifstream stream(file_path);
    if( stream )
    {
        std::string result;
        return result;
    }
    return {};
}

int main() {
  // std::optional require c++17
  std::cerr << LoadFile("verona.csv")
              .value_or("File [nw_verona.csv] could not be opened!")
       << "\n";
  ifstream ifile1("verona.csv");
  if (ifile1) {
    std::cout << "File opened\n";
    vector<vector<string>> data;
    string line, word;
    while (getline(ifile1, line)) {
      std::stringstream ss(line);
      vector<string> row;
      while (getline(ss, word, ',')) {
        row.push_back(word);
      }
      data.push_back(row);
    }    
    }
}

