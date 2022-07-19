#include <iostream>
#include <vector>
#include <map>

std::vector<int> brute(std::vector<int> nums, int target){
    int start{0};
    auto end{nums.size()};
    std::vector<int> result;

    for(int i{start}; i < end; i++){
        int one{nums[i]};
        for( int j {i}; j < end; j++){
            int two{nums[j]};
            if ((one+two) == target && i != j){
                result.push_back(i);
                result.push_back(j);
            }
        }
    }
    for (auto &v: result){
        std::cout<< "brute result: " << v << std::endl;
    }
    return result;
}

std::vector<int> hashmap(std::vector<int> nums, int target){
    
    std::map<int, int> mapping;
    std::vector<int> result;

    for (int i{0}; i < nums.size(); i++){

        int want = target - nums[i];
        std::cout << "i: " << i << std::endl;
        for(auto & m: mapping){
            std::cout << "mapping key: " << m.first << " mapping value: " << m.second << std::endl;
        }

        if (mapping.find(want) != mapping.end()) {
            result.push_back(i);
            result.push_back(mapping[want]);
            break;
        }

        mapping[nums[i]] = i;
    }

    for(auto &v: result){
        std::cout << "hashmap: " << v <<std::endl;
    }

    return result;
    
}



int main() {
    std::vector<int> nums_arr{3,3};
    int target{9};
    brute(nums_arr, target);
    std::cout <<std::endl;
    hashmap(nums_arr, target);
    
    return 0;
}