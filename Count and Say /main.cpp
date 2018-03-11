#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
	vector<int> getNext(vector<int>& v) {
		int cnt=0, val=0;
		vector<int> ret;
		for(int i=0; i<v.size(); i++) {
			if(i==0) {
				val = v[i];
				cnt = 1;
				continue;
			}
			if(v[i]==val) {
				cnt++;
			}else {
				ret.push_back(cnt);
				ret.push_back(val);
				val = v[i];
				cnt = 1;
			}
		}
		if(cnt>0 && val>0) {
			ret.push_back(cnt);
			ret.push_back(val);
		}
		return ret;
	}
	string vecToStr(vector<int>& v) {
		stringstream s;
		for(int i=0; i<v.size(); i++) {
			s << v[i];
		}
		return s.str();
	}
    string countAndSay(int n) {
        if(n==0) return "";
        if(n==1) return "1";
        vector<int> v{1};
        for(int i=1; i<n; i++) {
        	v = getNext(v);
        }
        string s = vecToStr(v);
        return s;
    }
};

int main()
{
	Solution s;
	cout << s.countAndSay(6) << endl;
	return 0;
}
