#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string str, longest;    
        for(int i=0; i<s.size(); i++)
        {
            str = findPalindrome(s, i, i);
            if(str.size() > longest.size())
                longest = str;
            str = findPalindrome(s, i, i+1);
            if(str.size() > longest.size())
                longest = str;
        }
        return longest;
    }
private:
    string findPalindrome(string s, int left, int right)
    {
        int n = s.size();
        while(left>=0 && right<=n-1 && s[left]==s[right])
        {
            left--;
            right++;
        }
        left++;
        right--;
    return s.substr(left, right-left+1);                
    }
};


int main(int argc, char** argv)
{
    string a = "babad";
    Solution s;
    cout << "result: " << s.longestPalindrome(a) << endl;
}
