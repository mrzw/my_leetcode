#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        const char *p = s.c_str();
        int length = 0, result = 0;
        for(;*p;p++) {
        	if(*p==' ') length = 0;
        	else result = ++length;
        }
        return result;
    }
};

int main(int argc, char** argv) {

}
