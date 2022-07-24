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
    cout << name << ". ";
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
    cout << "print name: " << name << endl;
    for (auto &v: vector_2d){
        cout << "1 dimensional index: " << one_dimensional_index << endl;
        one_dimensional_index++;
        for(auto &e: v){
            cout << "value: " << e << endl;
        }
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

vector<vector<int>> reshape(vector<vector<int>> &mat, int r, int c){

    vector<vector<int>> ans(r, vector<int> (c, 0));
    if (mat.size() == 0) return mat;

    if (mat.size() * mat[0].size() != r * c) return mat;

    int row = 0;
    int col = 0;
    
    for(int i{0}; i < mat.size(); i++){
        for(int j = 0; j < mat[0].size(); j++){
            ans[row][col] = mat[i][j];
            col++;

            if(col == c){
                col = 0;
                row++;
            }
        }
    }
    

    print<string, vector2d>("2d result: ", ans);
    return ans;
}


vector<vector<int>> reshape2(vector<vector<int>> &mat, int r, int c){
    vector<vector<int>> ans(r, vector<int> (c, 0));
    int org_m = mat.size();
    int org_n = mat[0].size();
    if (org_m == 0) return mat;
    if (org_m * org_n != r * c) return mat;
    
    for(int i{0}; i < org_m*org_n; i++){
        int org_x = i/org_n;
        int org_y = i%org_n;
        int new_x = i/c;
        int new_y = i%c;
        cout << "org_x: " << org_x << endl;
        cout << "org_y: " << org_y << endl;
        cout << "new_x: " << new_x << endl;
        cout << "new_y: " << new_y << endl;
        cout << endl;
        ans[new_x][new_y] = mat[org_x][org_y];
    }
    print<string, vector2d>("reshpe2 2d result: ", ans);
    
    return ans;

    
    
}


int main() {
    vector<vector<int>> mat 
    {
        {1,2},
        {3,4}
    }; 
    int r = 1;
    int c = 4;
    print<string, vector2d>("2d", mat);
    cout << endl;
    reshape(mat, r, c);
    cout << endl;
    reshape2(mat,r,c);



    return 0;
}