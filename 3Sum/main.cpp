#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
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
                if(a+b+c==0)
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
                else if(a+b+c>0)
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
};

void printMatrix(vector<vector<int> > &matrix)
{
    for(int i=0; i<matrix.size(); i++){
        printf("{");
        for(int j=0; j< matrix[i].size(); j++) {
            printf("%3d ", matrix[i][j]) ;
        }
        printf("}\n");
    }
}

int main(int argc, char** argv)
{
    Solution s;
    int a[] = {-1, 0, 1, 2, -1, -4};
    vector<int> v(a, a+sizeof(a)/sizeof(int));
    vector<vector<int> > result = s.threeSum(v);
    printMatrix(result);
    return 0;
}
