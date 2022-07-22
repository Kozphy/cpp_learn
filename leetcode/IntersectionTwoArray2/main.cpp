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
    int p1 = 0;
    int p2 = 0;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    print("nums1",nums1);
    print("nums2", nums2);
    vector<int> result;

    while (p1 < nums1.size() && p2 < nums2.size()){
        if(nums1[p1] > nums2[p2]) {
            p2++;
        } else if(nums1[p1] < nums2[p2]) {
            p1++;
        }else{
            result.push_back(nums1[p1]);
            p1++;
            p2++;
        }
    }
    print("result", result);
    return result;
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