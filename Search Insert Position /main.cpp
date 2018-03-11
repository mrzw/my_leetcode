#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int binary_search(vector<int>& A, int low, int high, int key){
    while (low<=high) {
        int mid = low + (high-low)/2;
        if (A[mid] == key) {
            return mid;
        }
        if (key > A[mid]) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
        return low;
    }
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0) return 0;
        int result = binary_search(nums, 0, n-1, target);
        return result;
    }
};

int main()
{
    
}
