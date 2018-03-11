#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        return x == reverse(x);
    }
    bool isPalindrome2(int x) {
        if (x<0) {
            return false;
        }
        
        int len=1;
        for (len=1; (x/len) >= 10; len*=10 );
        
        while (x != 0 ) {
            int left = x / len;
            int right = x % 10;
            
            if(left!=right){
                return false;
            }
            
            x = (x%len) / 10;
            len /= 100;
        }
        return true;
}
private:
    int reverse(int x)
    {
        long result = 0;
        while(x)
        {
            result = result*10 + x%10;
            x /= 10;
            if(result>INT_MAX or result<INT_MIN)
                return 0;
        }
        return result;
    }
};

int main(int argc, char** argv)
{
    Solution s;
    int a = 12341;
    cout << s.isPalindrome(a) << endl;
}
