#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int result = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] != val) nums[result++] = nums[i];
        }
        return result;
    }
};

int main(int argc, char** argv)
{
    
}
