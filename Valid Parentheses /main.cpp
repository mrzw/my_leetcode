#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
bool isValid(string s) {
    stack<char> st;
    for(auto ch : s) {
        if (ch=='{' || ch =='[' || ch=='(' ) {
            st.push(ch);
        }else if (ch=='}' || ch ==']' || ch == ')' ){
            if (st.empty()) return false;
            char sch = st.top();
            if ( (sch=='{' && ch =='}') || (sch=='[' && ch==']') || (sch=='(' && ch==')' ) ){
                st.pop();
            }else {
                return false;
            }
        }else{
            return false;
        }
    }
    return st.empty();
}
};

int main(int argc, char** argv)
{
    Solution s;
    cout << s.isValid(a) << endl;    
}
