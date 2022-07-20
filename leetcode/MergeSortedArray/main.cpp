#include <iostream>
#include <vector>

void print(int id, const std::vector<int>& container)
{
    std::cout << id << ". ";
    for (const int x: container) {
         std::cout << x << ' ';
    }
    std::cout << '\n';
}
 

using namespace std;

vector<int> merge(vector<int> &nums1, int &m, vector<int> &nums2, int &n){

    int p1 = m - 1;
    int p2 = n - 1;
    int nums1_index = static_cast<int>(nums1.size()-1);

    
    while(p2 >= 0){
        cout << "nums1_index: " << nums1_index << endl;
        cout << "p1: " << p1 << endl;
        cout << "p1_v: " << nums1[p1] << endl;
        cout << "p2: " << p2 << endl;
        cout << "p2_v: " << nums2[p2] << endl;


        if (p1 == -1 || nums1[p1] <= nums2[p2]){
            nums1[nums1_index] = nums2[p2];
            p2--;
        } else if(nums1[p1] > nums2[p2]) {
            nums1[nums1_index] = nums1[p1];
            p1--;
        }

        nums1_index--;
        print(0, nums1);
        cout << endl;
    }


    return nums1;
}

int main() {
    vector<int> nums1 {4,5,6,0,0,0};
    vector<int> nums2 {1,2,3};
    int m {3};
    int n {3};
    merge(nums1, m, nums2, n);
    return 0;
}