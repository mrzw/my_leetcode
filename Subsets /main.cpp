// https://github.com/pezy/LeetCode/tree/master/077.Subsets
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int size = pow(2, nums.size());
        vector<vector<int>> result(size);
        for(int i=0; i<size; i++) {
            for(int j=0; j<nums.size(); j++) {
                if(i>>j & 1) {
                    result[i].push_back(nums[j]);
                }
            }
        }
        return result;
    }
};
int main(int argc, char** argv) {
    vector<int> a{1,2,3};
    Solution s;
    vector<vector<int>> result = s.subsets(a);
    for(auto &i:result) {
        for(auto &j:i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
