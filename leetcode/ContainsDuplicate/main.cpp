#include <iostream>
#include <map>
#include <vector>

bool containsDuplicate(std::vector<int> nums){
    std::map<int, int> simmap;
    for(size_t i{}; i < std::size(nums); i++){
        if(simmap[nums[i]] == 1){
            return true;
        }
            
        if(simmap[nums[i]] == 0) {
            simmap[nums[i]] = 1;
        }
    }
    return false;
}

int main() {
    std::vector<int> nums {1,2,3,4,1};
    bool result = containsDuplicate(nums);
    std::cout<< result << std::endl;
    return 0;
}