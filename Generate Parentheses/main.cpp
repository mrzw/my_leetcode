#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> result;
        string s;
        generator(result, n, n, s);
        return result;
    }
    void generator(vector<string>& result, int left, int right, string s)
    {
        if(left==0 && right==0)
        {
            result.push_back(s);
            return;
        }
        if (left>0) generator(result, left-1, right, s+'(');
        if (right>0 && right>left)  generator(result, left, right-1, s+')');
    }
};

int main(int argc, char** argv)
{
    Solution S; 
    vector<string> a = S.generateParenthesis(3);
    //for(auto str:a) cout << str << endl;
    for(int i=0; i<a.size(); i++)   cout << a[i] << endl;
}
