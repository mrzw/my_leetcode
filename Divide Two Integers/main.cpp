#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
int divide(int dividend, int divisor) {
    int sign = (dividend<0 && divisor<0)||(dividend>0 && divisor>0) ? 1 : -1;   
    unsigned int dvd = dividend > 0 ? dividend : -dividend;
    unsigned int dvs = divisor > 0 ? divisor : -divisor;

    unsigned int bit_num[33];
    unsigned int i=0;
    long long d = dvs;
    bit_num[i] = d;
    while( d <= dvd ){
        bit_num[++i] = d = d << 1;
    }
    i--;

    unsigned int result = 0;
    while(dvd >= dvs){
        if (dvd >= bit_num[i]){
            dvd -= bit_num[i];
            result += (1<<i);
        }else{
            i--;
        }
    }

    if ( result > INT_MAX && sign > 0 ) {
        return INT_MAX;
    }
    return (int)result * sign;
    }
};

int main()
{
    
}
