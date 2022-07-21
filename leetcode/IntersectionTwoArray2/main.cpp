#include <iostream>
#include <vector>
#include <map>
#include <string>

void print(int id, const std::vector<int>& container)
{
    std::cout << id << ". ";
    for (const int x: container) {
         std::cout << x << ' ';
    }
    std::cout << '\n';
}
 
 void print_map(std::string name,std::map<int, int> mapping){
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

vector<int> brute(vector<int> nums1, vector<int> nums2){
    vector<int> result;
    for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]){
                    result.push_back(nums1[i]);
                    nums2.erase(nums2.begin() + j);
                    break;
                }
            }
    }
   print(0, result);
   return result;
}

vector<int> intersection_hashmap(vector<int> nums1, vector<int> nums2){
    map<int, int> mapping_nums2;
    create_hashmap(nums2,mapping_nums2);
    vector<int> result;

    for (int i{0}; i < nums1.size(); i++){
        if (mapping_nums2.find(nums1[i]) != mapping_nums2.end() && mapping_nums2[nums1[i]] > 0){
            mapping_nums2[nums1[i]]--;
            result.push_back(nums1[i]);
        }
    }
    print(0, result);

    return result;
}

vector<int> intersection_two_point(vector<int> nums1, vector<int> nums2){
    int p1 = static_cast<int>(nums1.size()) - 1;
    int p2 = static_cast<int>(nums2.size()) - 1;
}

int main() {
    vector<int> nums1 {1,2,2,1};
    vector<int> nums2 {2};

    brute(nums1, nums2);
    cout << endl;
    intersection_hashmap(nums1, nums2);
    cout << endl;
    intersection_two_point(nums1, nums2);

    return 0;
}