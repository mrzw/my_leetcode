#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n-1;
        for(int i=0; i<=end; i++) {
            if(nums[i]==0) {
                int temp = nums[start];
                nums[start] = nums[i];
                nums[i] = temp;
                start++;
            }
            if(nums[i]==2) {
                int temp = nums[end];
                nums[end] = nums[i];
                nums[i] = temp;
                end--;
                i--;
            }
        }
    }
};
int main(int argc, char** argv) {
    vector<int> a{2,0,2,1,1,0};
    Solution s;
    s.sortColors(a);
    for(auto &i: a) {
        cout << i << " ";
    }
}
