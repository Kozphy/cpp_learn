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

// bool validSudoku(vector2d<char> &board){
//     map<string, int> row_mapping{};
//     map<string, int> col_mapping{};
//     map<string, int> grid_mapping{};

//     for (int i{0}; i < 9;  i++){
//         for(int j{0}; j < 9; j++){
//             cout << "row, col: " << i << "," << j << endl;
//             // check row
//             if(row_mapping.find(board[i][j]) != row_mapping.end()){
//                 return false;
//             }else{
//                 if (board[i][j] != ".") {
//                     row_mapping[board[i][j]] = 1;
//                 }
//             }

//             // check col
//             // cout << "board[j][i]: " << board[j][i] << endl;
//             if(col_mapping.find(board[j][i]) != col_mapping.end()){
//                 return false;
//             }else{
//                 if (board[j][i] != ".") {
//                     col_mapping[board[j][i]] = 1;
//                 }
//             }
//             //check grid
//             int grid_row_coordinate = i / 3;
//             int grid_col_coordinate = j / 3;
//             int coordinate = grid_row_coordinate + grid_col_coordinate;
//             string k{to_string(coordinate) + board[i][j]};
//             if(grid_mapping.find(k) != grid_mapping.end()){
//                 return false;
//             }else{
//                 if (board[i][j] != ".") {
//                     grid_mapping[k] = 1;
//                 }
//             }
            
//         }
//             print("row_map ", row_mapping);
//             print("col_map ", col_mapping);
//             print("grid_mapping", grid_mapping);
//             row_mapping.clear();
//             col_mapping.clear();
//             grid_mapping.clear();
//     }

//     return true;
// }

int main() {
    // TODO: fix string and char type issue
    vector2d<char> board
    {
        {"5","3",".",".","7",".",".",".","."}
        ,{"6",".",".","1","9","5",".",".","."}
        ,{".","9","8",".",".",".",".","6","."}
        ,{"8",".",".",".","6",".",".",".","3"}
        ,{"4",".",".","8",".","3",".",".","1"}
        ,{"7",".",".",".","2",".",".",".","6"}
        ,{".","6",".",".",".",".","2","8","."}
        ,{".",".",".","4","1","9",".",".","5"}
        ,{".",".",".",".","8",".",".","7","9"}
    };
    // bool result = validSudoku(board);
    // cout << boolalpha;
    // cout << "result: "  << result << endl;


    return 0;
}