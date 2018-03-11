#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int maxLen = 0, lastRepeat = -1;
        for(int i=0; i<s.size(); i++)
        {
            if(m.find(s[i])!=m.end() && lastRepeat<m[s[i]])
                lastRepeat = m[s[i]];
            if(i-lastRepeat>maxLen)
                maxLen = i - lastRepeat;
            m[s[i]] = i;
        }
        return maxLen;
    }
};

int main(int argc, char** argv)
{
    string a = "pwwkew";
    Solution s;
    cout << s.lengthOfLongestSubstring(a) << endl;
}
