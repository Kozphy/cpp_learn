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

int firstUniqueCharInString(string &s){
    map<char, int> mapping_count;
    map<char, int> mapping_index;
    int index = 0;

    for(auto &v: s) {
        if (mapping_count.count(v)){
            mapping_count[v]++;

        }else{
            mapping_count[v] = 1;
            mapping_index[v] = index;
        }
        index++;
    }

    int smaller = 999999;
    for(auto &[k, v]: mapping_count){
        if (v == 1 && smaller > mapping_index[k]){
            smaller = mapping_index[k];
        }
    }

    if (smaller == 999999){
        return -1;
    }
    return smaller;

}

int firstUniqueCharInString_queue(string &s){
    map<char, int> mapping;
    queue<char> qu;

    for(int i = 0; i < s.length(); i++){
        qu.push(s[i]);
        if(mapping.count(s[i])){
            mapping[s[i]]++;
        }else{
            mapping[s[i]] = 1;
        }
    }

    for (int i = 0; i < s.length(); i++){
        if(mapping[qu.front()] == 1){
            return i;
        }
        qu.pop();
    }
    return -1;

}

int firstUniqueCharInString3(string &s){
    return -1;
}


TODO: improve execute time
int main() {
    string s = "loveleetcode";
    int result = firstUniqueCharInString(s);
    cout << "result: " << result << endl;
    cout << endl;
    int result_queue = firstUniqueCharInString_queue(s);
    cout << "result queue: " << result_queue << endl;
    cout << endl;
    int result3 = firstUniqueCharInString3(s);
    cout << "result 3: " << result3 << endl;




    return 0;
}