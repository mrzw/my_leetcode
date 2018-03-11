#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int binary_search(int A[], int n, int key) {
        int low = 0;
        int high = n-1;
        while (low <= high){
            int mid = low +(high-low)/2;
            if (A[mid] == key){
                return mid;
            }
            if ( key> A[mid] ) {
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n<=0) return -1;
        if(n==1) return nums[0]==target ? 0:-1;
        int low = 0, high = n-1;
        while(low<=high)
        {
            if (nums[low] <= nums[high] && (target < nums[low] || target > nums[high])) return -1;
            int mid = low+(high-low)/2;
            if(nums[mid]==target) return mid;
            if(nums[low]<nums[mid] && nums[low]<=target && target<nums[mid])
            {
                high = mid - 1;
                continue;
            }
            if(nums[mid]<nums[high] && nums[mid]<target && target<=nums[high])
            {
                low = mid + 1;
                continue;
            }
            if(nums[low]>nums[mid])
            {
                high = mid -1;
                continue;            
            }
            if(nums[mid]>nums[high])
            {
                low = mid + 1;
                continue;
            }
        }
        return -1;
    }
};

int main()
{
    int a[] = {4, 5, 6, 7, 0, 1, 2};
    vector<int> b(a, a+sizeof(a)/sizeof(int));
    Solution s;
    cout << s.search(b, 1) << endl;
}
