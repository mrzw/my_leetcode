#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()<=0) return "";
        for(int i=0; i<strs[0].size(); i++)
        {
            char temp = strs[0].at(i);
            for(int j=1; j<strs.size(); j++)
            {
                if(i+1>strs[j].size() || temp!=strs[j].at(i))
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};

int main(int argc, char** argv)
{
    Solution s;
    const char* a[]={"aaa","aa","aaa"};
    vector<string> v(a, a+3);
    cout << s.longestCommonPrefix(v) <<endl;
}
