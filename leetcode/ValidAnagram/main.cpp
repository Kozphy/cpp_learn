#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <queue>


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

bool ValidAnagram(string &s, string &t){
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if (s.length() != t.length()){
        return false;
    }

    for (int i =0;i<s.length();i++){
        if(s[i] != t[i]){
            return false;
        }
    }
    return true;

}


// TODO: improve execute time
int main() {
    string s = "rat";
    string t = "cat";
    bool result = ValidAnagram(s, t);
    cout << boolalpha;
    cout << "result: " << result << endl;
    cout << endl;





    return 0;
}