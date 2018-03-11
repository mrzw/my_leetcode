#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1) return;
        for(int i=nums.size()-1; i>=1; i--)
        {
            if(nums[i-1]<nums[i])
            {
                int j = nums.size()-1;
                while(nums[i-1]>=nums[j]) j--;
                int temp = nums[i-1];
                nums[i-1] = nums[j];
                nums[j] = temp;
                reverse(nums.begin()+i, nums.end());
                return;
            }
            if(i==1)
            {
                reverse(nums.begin(), nums.end());
                return;
            }
        }
    }
};

int main()
{
    int a[] = {3,2,1};
    vector<int> b(a, a+sizeof(a)/sizeof(int));
    Solution s;
    s.nextPermutation(b);
    for(auto i:b)
        cout<<i<<endl;
}
