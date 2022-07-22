#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

template <typename T, typename C>
void print(T name, const C &container)
{
    std::cout << name << ". ";
    for (const int x: container) {
         std::cout << x << ' ';
    }
    std::cout << '\n';
}

 template <typename T, typename C>
 void print(std::string name,std::map<int, int> &mapping){
    std::cout << "print map name: " << name << std::endl;
    for (auto &v: mapping){
        std::cout << v.first << " : " << v.second << std::endl;
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

int brute(vector<int> prices){
    int max_profit{0};
    
    for(int i{0}; i < prices.size(); i++){
        for(int j{i}; j < prices.size(); j++){
            if (prices[i] < prices[j]){
                if (max_profit < (prices[j] - prices[i])){
                    max_profit = prices[j] - prices[i];
                }
            }
        }
    }
    cout << max_profit << endl;
    return max_profit;
}

int dynamic(vector<int> prices){
    int max_profit{0};
    int smaller_value{100000};
    
    for (int i = 0; i < prices.size(); i++){
        if(smaller_value > prices[i]){
            smaller_value = prices[i];
        }else if(smaller_value < prices[i] && max_profit < (prices[i] - smaller_value)){
            max_profit = prices[i] - smaller_value;
        }
    }
    cout << "dynamic: " << max_profit << endl;
    return max_profit;
    
}

int main() {
    vector<int> prices {7,6,4,3,1}; 
    brute(prices);
    cout << endl;
    dynamic(prices);


    return 0;
}