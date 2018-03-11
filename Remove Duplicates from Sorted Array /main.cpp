#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        int result = 0;        
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i] != nums[i+1]) nums[++result] = nums[i+1];
        }
        return result+1;
    }
};

int main(int argc, char** argv)
{
    
}
