#include <iostream>
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
        if (key < A[mid]) {
            high = mid - 1;
        }
    }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int index = binary_search(nums, 0, nums.size()-1, target);
        int low=-1, high=-1;
        if(index>=0)
        {
            low = high = index;
            int l = low;
            do {
                low = l;
                l = binary_search(nums, 0, low - 1, target);
            }while (l>=0);

            int h = high;
            do {
                high = h;
                h = binary_search(nums, high + 1, nums.size()-1, target);
            }while (h>=0);
            return {low, high};
        }
        else return {-1,-1};
    }
};

int main()
{
    
}
