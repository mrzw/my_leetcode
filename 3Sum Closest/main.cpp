#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result;
        if(nums.size()==0 || nums.size()==1 || nums.size()==2)  return INT_MAX;
        sort(nums.begin(), nums.end());
        int a, b, c, start, end;
        int n = nums.size();
        int thres = INT_MAX;
        int sum;
        for(int i=0; i<n-2; i++)
        {
            if (i>0 && nums[i-1]==nums[i]) continue;
            a = nums[i];
            start = i+1;
            end = n-1;
            while(start < end)
            {
                b = nums[start];
                c = nums[end];
                sum = a+b+c;
                if(sum-target==0) return target;
                if(abs(sum-target)<thres)
                {
                    thres = abs(sum - target);
                    result = sum;                    
                }
                if(sum-target>0)
                {
                    while(end>0 && (nums[end]==nums[end-1])) end--;
                    end--;
                }
                else
                {
                    while(start<n-1 && (nums[start]==nums[start+1])) start++;
                    start++;                    
                }                  
            }
        }
        return result;        
    }
};

int main(int argc, char** argv)
{
    Solution s;
    int a[] = {1,1,1,0};
    vector<int> v(a, a+sizeof(a)/sizeof(int));
    int result = s.threeSumClosest(v, -100);
    cout << result << endl;
    return 0;
}
