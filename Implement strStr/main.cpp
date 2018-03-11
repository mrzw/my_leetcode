#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0) return 0;
        if(haystack.size() < needle.size()) return -1;
        for(int i=0; i<=haystack.size()-needle.size(); i++)
        {
            bool match = true;
            for(int j=0; j<needle.size(); j++)
            {
                if(haystack.at(i+j) != needle.at(j)) 
                {
                    match = false;
                    break;
                }
            }
            if(match) return i;
        }
        return -1;
    }
};

int main(int argc, char** argv)
{
    string a="a", b="a";
    Solution s;
    cout << s.strStr(a, b) << endl;
}
