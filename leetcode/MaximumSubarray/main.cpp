#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <limits>

int brute(std::vector<int> nums);
int kadane_algo(std::vector<int> nums);

int main() {
    std::vector<int> nums {5,4,-1,7,8};
    brute(nums);
    std::cout << std::endl;
    kadane_algo(nums);
    return 0;
}

int brute(std::vector<int> nums)
{
    int start{0};
    auto end {nums.size()};
    int max{std::numeric_limits<int>::min()};

    std::printf("i j : sum\n");
    for (int i{start}; i < end; i++){
        for(int j{i}; j < end; j++){
            int sum{0};
            for (int k = i; k <= j; k++){
                sum+=nums[k];
            }

            if (sum > max){
                max = sum;
            }
            printf("%d %d: %d\n",i,j,sum);
        }
    }
    std::cout << "brute: "  << max << std::endl;
    return max;
    
}

int kadane_algo(std::vector<int> nums)
{
    std::vector<int> max_arr{};

    for (int i{0}; i < std::size(nums); i++){
        if (i == 0){
            max_arr.push_back(nums[i]);
            continue;
        }

        if (max_arr[i - 1] > 0){
            max_arr.push_back(nums[i] + max_arr[i - 1]);
        }

        if (max_arr[i - 1] < 0){
            max_arr.push_back(nums[i]);
        }
    }

    for (auto &v : max_arr){
        std::cout << v << std::endl;
    }
    std::vector<int>::iterator result;
    result = std::max_element(max_arr.begin(), max_arr.end());

    std::cout << "max: " << *result << std::endl;


    return 0;
}


