#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::vector;
using std::string;
// C++11 version
int main(){

    std::ifstream ifile1("verona.csv");
    if(ifile1){
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

