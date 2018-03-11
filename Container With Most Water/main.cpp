#include <iostream>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxResult = 0, temp = 0;
        int left = 0, right = height.size()-1;
        while(left < right)
        {
            temp = (right - left) * ( height[left] < height[right] ? height[left] : height[right]);
            maxResult = temp > maxResult ? temp : maxResult;
            height[left] < height[right] ? left++ : right--;
        }
        return maxResult;
    }
};

int main(int argc, char** argv)
{
    
}
