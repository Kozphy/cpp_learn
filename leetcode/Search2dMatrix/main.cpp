#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>


using namespace std;

template <typename T>
using vector2d = vector<vector<T>>;

template <typename C>
void print(string name, const vector<C> &vector_1d)
{
    cout << name << ": ";
    for (const auto &x: vector_1d) {
         cout << x << ' ';
    }
    cout << '\n';
}

template <typename T, typename C>
void print(string name, map<T, C> &mapping){
    cout << "print map name: " << name << endl;
    for (auto &v: mapping){
        cout << v.first << " : " << v.second << endl;
    }
}

template <typename C>
void print(string name, vector2d<C> &vector_2d){
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

template<typename T, typename C>
bool create_hashmap(vector<T> &nums, map<T, C> &mapping){
    for (auto &v: nums){
        if (mapping.find(v) != mapping.end()){
            mapping[v] += 1;
        }else {
            mapping[v] = 1;
        }
    }
    return true;
}

bool searchMatrix(vector2d<int> &matrix, int target){
    
    int row = static_cast<int>(matrix.size());
    int col = static_cast<int>(matrix[0].size());


    for(int i = 0; i < row; i++){
        int left_p = 0;
        int right_p = col - 1;
        for(int j = 0; j < col; j++){
            if (target > matrix[i][col-1]){
                continue;
            }else{
                int mid = (left_p + right_p) / 2;
                cout << "mid: " << mid << endl;
                cout << "left_p: " << left_p <<  endl;
                cout << "right_p: " << right_p << endl;
                cout << "matrix[i][mid]: " << matrix[i][mid] << endl;
                if(target == matrix[i][mid]) {
                    return true;
                }else if(target > matrix[i][mid]){
                    left_p = ++mid;
                }else{
                    right_p = --mid;
                }
                cout << endl;
            }
        }
    }
    return false;
}


int main() {
    vector2d<int> matrix
    {
        {1,3},
    };
    int target = 3;
    bool result = searchMatrix(matrix, target);
    cout << "result: " << result << endl;
    



    return 0;
}