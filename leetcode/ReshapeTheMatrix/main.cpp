#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

template <typename T, typename C>
void print(T name, const C &container)
{
    std::cout << name << ". ";
    for (const auto &x: container) {
         std::cout << x << ' ';
    }
    std::cout << '\n';
}

template <>
void print<std::string, std::map<int,int>>(std::string name,std::map<int, int> &mapping){
    std::cout << "print map name: " << name << std::endl;
    for (auto &v: mapping){
        std::cout << v.first << " : " << v.second << std::endl;
    }
}

template <>
void print<std::string, std::vector<vector<int>>>(std::string, std::vector<std::vector<int>> &vector2d){
    for (auto &v: vector2d){
        for(auto &e: v){
            std::cout << e << std::endl;
        }
    }
}

using namespace std;


void create_hashmap(vector<int> &nums, map<int, int> &mapping){
    for (auto &v: nums){
        if (mapping.find(v) != mapping.end()){
            mapping[v] += 1;
        }else {
            mapping[v] = 1;
        }
    }
}

vector<vector<int>> brute(vector<vector<int>> &mat, int r, int c){
    
    return ;
}



int main() {
    vector<vector<int>> mat {{1,2}, {3,4}}; 
    int r = 1;
    int c = 4;
    // brute(mat, r, c);
    print<string, vector<vector<int>>("2d", mat);
    cout << endl;



    return 0;
}