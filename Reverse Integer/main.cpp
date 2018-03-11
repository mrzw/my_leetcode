#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long result=0;        
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
    cout<<s.reverse(123)<<endl;
    cout<<s.reverse(-123)<<endl;
    cout<<s.reverse(120)<<endl;    
}
