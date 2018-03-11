#include <iostream>
using namespace std;

// 大数乘法
class Solution {
public:
	string singleMultiply(string &nums, char ch) {
		string result;
		int carry = 0;
		for(int i=nums.size()-1; i>=0; i--) {
			int a = (nums[i]-'0')*(ch-'0') + carry;
			carry = a/10;
			result.insert(result.begin(), a%10+'0');
		}
		if(carry>0) {
			result.insert(result.begin(), carry+'0');
		}
		return result;
	}
	string addStr(string &num1, string &num2) {
		string result;
		int n1 = num1.size(), n2 = num2.size();
		int carry = 0;
		for(int i=n1-1, j=n2-1; i>=0 || j>=0; i--, j--) {
			int a = i>=0?(num1[i]-'0'):0;
			int b = j>=0?(num2[j]-'0'):0;
			int c = a + b + carry;
			carry = c/10;
			result.insert(result.begin(), c%10+'0');
		}
		if(carry>0) {
			result.insert(result.begin(), carry+'0');
		}
		return result;
	}
    string multiply(string num1, string num2) {
		int n1 = num1.size(), n2 = num2.size();
		int shift = 0;
		string result="0";
		for(int i=n1-1; i>=0; i--) {
			string s = singleMultiply(num2, num1[i]);
        	for(int j=0; j<shift; j++){
            	s.insert(s.end(), '0');
			}
			shift++;
			result = addStr(result, s);
		}
		if(result[0]=='0') return "0";
		return result;
    }
    
    string multiply1(string num1, string num2) {
        string ret(num1.size() + num2.size(), '0');
        for (int i = num1.size()-1; i >= 0; --i) {
            int carry = 0;
            for (int j = num2.size()-1; j >= 0; --j) {
                int sum = (ret[i+j+1]-'0') + (num1[i]-'0') * (num2[j]-'0') + carry;
                ret[i+j+1] = sum%10 + '0';
                carry = sum/10;
            }
            ret[i] += carry;
        }
        size_t pos = ret.find_first_not_of('0');
        if (pos != string::npos) return ret.substr(pos);
        else return "0";
	}	
};

int main(int argc, char** argv) {
	string s1="123";
	string s2="456";
	Solution s;
	cout << s.multiply(s1, s2) << endl;
}
