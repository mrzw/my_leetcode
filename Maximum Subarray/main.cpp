#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int result = nums[0];
        int temp = nums[0];
        for(int i=1; i<n; i++) {
        	temp = max(nums[i], temp+nums[i]);
        	result = max(result, temp);
        }
        return result;
    }
};

int main(int argc, char** argv) {
	vector<int> a{-2,1,-3,4,-1,2,1,-5,4};
	Solution s;
	cout << s.maxSubArray(a) << endl;		
}
