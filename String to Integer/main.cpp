#include <iostream>
#include <string>
#include <cctype>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        const char *ptr = str.c_str();

        if(ptr==NULL || *ptr=='\0')
            return 0;

        for(; isspace(*ptr); ptr++);
        bool neg = false;        
        if(*ptr=='-' || *ptr=='+')
        {
            neg = (*ptr=='-');
            ptr++;
        }
        int result = 0;
        long temp = 0;
        for(; isdigit(*ptr); ptr++)
        {
            int a = *ptr - '0';
            cout << *ptr << endl;
            temp = temp*10 + a;
            if(neg && (-temp < INT_MIN))
                return INT_MIN;
            if(!neg && (temp > INT_MAX))
                return INT_MAX;
        }
        result = neg?-temp:temp;
        return result;
    }
};

int main(int argc, char** argv)
{
    Solution s;
    string a="adf123adf";
    cout << s.myAtoi(a) << endl;
}
