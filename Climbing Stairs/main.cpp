#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	// 斐波那契数列
    int climbStairs(int n) {        
        if(n<3) return n;
        int res=0, a=1, b=2;
        for(int i=0; i<n-2; i++) {
        	res = a+b;
        	a = b;
        	b = res;
        }
        return res;
    }
};
int main(int argc, char** argv) {

}
