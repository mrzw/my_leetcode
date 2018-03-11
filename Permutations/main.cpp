#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > vv;
        vv.push_back(nums);
        if(nums.size()<2) {
        	return vv;
        }
        for(int pos=0; pos<nums.size()-1; pos++) {
        	int n = vv.size();
        	for(int i=0; i<n; i++) {
        		for(int j=pos+1; j<vv[i].size(); j++) {
        			vector<int> v = vv[i];
        			int temp = v[j];
        			v[j] = v[pos];
        			v[pos] = temp;
        			vv.push_back(v);
        		}
        	}
        }
        return vv;
    }
};

int main(int argc, char** argv) {
	vector<int> a{1,2,3};
	Solution s;
	vector<vector<int> > result = s.permute(a);
	for(auto i:result) {
		for(auto j:i) {
			cout << j << " ";			
		}
		cout << endl;
	}		
}
