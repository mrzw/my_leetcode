#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums, int target) {
        vector<vector<int> > result;
        if(nums.size()==0 || nums.size()==1 || nums.size()==2)
            return result;
        sort(nums.begin(), nums.end());
        int a, b, c, start, end;
        int n = nums.size();
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
                if(a+b+c==target)
                {
                    vector<int> temp;
                    temp.push_back(a);
                    temp.push_back(b);
                    temp.push_back(c);
                    result.push_back(temp);
                    while(end>0 && nums[end]==nums[end-1]) end--;
                    while(start<n-1 && nums[start]==nums[start+1]) start++;
                    end--;
                    start++;
                }
                else if(a+b+c>target)
                     {
                        while(end>0 && nums[end]==nums[end-1]) end--;
                        end--;
                     }
                else 
                     {
                        while(start<n-1 && nums[start]==nums[start+1]) start++;
                        start++;
                     }                    
            }
        }
        return result;
    }

    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > result;
        if(nums.size() < 4)
            return result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<n-3; i++)
        {
            if (i>0 && nums[i-1]==nums[i]) continue;
            vector<int> a(nums.begin()+i+1, nums.end());
            vector<vector<int> > temp = threeSum(a, target-nums[i]);
            for(int j=0; j<temp.size(); j++)
            {
                temp[j].insert(temp[j].begin(), nums[i]);
                result.push_back(temp[j]);
            }
        }
        return result;
    }
};

int printMatrix(vector< vector<int> > &vv)
{
    for(int i=0; i<vv.size(); i++) {
        cout << "[";
        for(int j=0; j<vv[i].size(); j++) {
            cout << " " << vv[i][j];
        }
        cout << "]" << endl;;
    }
}

int main(int argc, char** argv)
{
    Solution s;
    int a[] = {1,0,-1,0,-2,2};
    vector<int> n(a, a+sizeof(a)/sizeof(int));
    vector<vector<int> > ss = s.fourSum(n, 0);
    printMatrix(ss);
    return 0;
}
