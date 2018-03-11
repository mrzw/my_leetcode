#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int max_index = 0;
        for(int i=0; i<=max_index&&i<n; i++) {
        	if(max_index<nums[i]+i) {
        		max_index = nums[i]+i;
        	}
        	if(max_index>=n-1) {
        		return true;
        	}
        }
        return false;
    }
};

int main(int argc, char** argv) {
	vector<int> a{3,2,1,0,4};
	Solution s;
	cout << s.canJump(a) << endl;		
}
