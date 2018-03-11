#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> result;
        for(int i=0; i<nums.size(); i++)
        {
            if(m.find(nums[i])==m.end())
            {
                m[target-nums[i]] = i;
            }
            else
            {
                result.push_back(m[nums[i]]);
                result.push_back(i);
                break;
            }
        }
        return result;
    }
};

int main(int argc, char** argv)
{
    vector<int> numbers;
    numbers.push_back(2);
    numbers.push_back(11);
    numbers.push_back(15);
    numbers.push_back(7);
    int tar = 26;
    Solution s;
    vector<int> out = s.twoSum(numbers, tar);
    cout << out[0] << " " << out[1] << endl;
}
