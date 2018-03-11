#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
		bool sign = false;
		unsigned int exp = n;
		if(n<0){
		    exp = -n;
		    sign = true;
		}
		double result = 1.0;
		while (exp) {
		    if (exp&1){
		        result *= x;
		    }
		    exp >>= 1;
		    x *= x;
		}
		return sign ? 1/result : result;        
    }
};

int main(int argc, char** argv) {
	
	Solution s;
	double result = s.myPow(2.1, 4);
	cout << result << endl;		
}
