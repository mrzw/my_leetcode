#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1 or numRows>s.size()) return s;
        vector<string> temp(numRows);
        string result;
        int row=0, step=1;
        for(int i=0; i<s.size(); i++)
        {
            if(row==0)  step=1;
            if(row==numRows-1) step=-1;
            temp[row] += s[i];
            row += step;
        }
        for(int i=0; i<numRows; i++)
            result += temp[i];
        return result;
    }
};

int main(int argc, char** argv)
{
    Solution s;
    string a;
    a = s.convert("PAYPALISHIRING", 3);
    cout << a << endl;
}
