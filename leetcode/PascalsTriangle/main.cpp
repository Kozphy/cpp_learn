#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>


using namespace std;

typedef vector<vector<int>> vector2d;

template <typename T, typename C>
void print(T name, const C &container)
{
    cout << name << ": ";
    for (const auto &x: container) {
         cout << x << ' ';
    }
    cout << '\n';
}

template <typename T, typename C>
void print(string name, map<int, int> &mapping){
    cout << "print map name: " << name << endl;
    for (auto &v: mapping){
        cout << v.first << " : " << v.second << endl;
    }
}

template <typename T, typename C>
void print(string name, vector2d &vector_2d){
    int one_dimensional_index{0};
    int two_dimensional_index {0};
    cout << "print name: " << name << endl;
    for (auto &v: vector_2d){
        cout << "1 dimensional index: " << one_dimensional_index << endl;
        one_dimensional_index++;
        for(auto &e: v){
            cout << "2 dimensional index: " << two_dimensional_index <<  " value: " << e << endl;
            two_dimensional_index++;
        }
        two_dimensional_index = 0;
    }
}


void create_hashmap(vector<int> &nums, map<int, int> &mapping){
    for (auto &v: nums){
        if (mapping.find(v) != mapping.end()){
            mapping[v] += 1;
        }else {
            mapping[v] = 1;
        }
    }
}

vector2d pascal(int numRows){
    vector2d result(numRows);
    for (int i{0}; i < numRows; i++){
        result[i].resize(i+1);
    }
    print<string, vector2d>("init result", result);


    for (int i{0}; i < numRows; i++) {
        for(int j{0}; j <= i; j++){
            cout << "row: " << i << endl;
            cout << "col: " << j << endl;
            cout << endl;
            if (j == 0 || j == i){
                result[i][j] = 1;
            }else{
                result[i][j] = (result[i - 1][j-1] + result[i - 1][j]);
            }
        }
    }
    print<string, vector2d>("pascal result", result);
    return result;
}

int main() {
    int numRows{5};
    pascal(numRows);
    cout << endl;


    return 0;
}