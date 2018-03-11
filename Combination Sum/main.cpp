#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void dfs(vector<int> &candidates, int start, int target, vector<int> &solution, vector<vector<int> > &result) {
		if(target==0) {
			result.push_back(solution);
			return;
		}
		for(int i=start; i<candidates.size(); i++) {
			if(candidates[i]>target) {
				break;
			}
			solution.push_back(candidates[i]);
			dfs(candidates, i, target-candidates[i], solution, result);
			solution.pop_back();
		}
	}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        if(candidates.size()<=0) {
        	return result;
        }
        sort(candidates.begin(), candidates.end());
        vector<int> solution;
        dfs(candidates, 0, target, solution, result);
        return result;
    }
};

int main(int argc, char** argv) {
	vector<int> v{2, 3, 6, 7};
	Solution s;
	vector<vector<int> > vv = s.combinationSum(v, 7);
	for(auto &i:vv) {
		for(auto j:i) {
			cout << j << " ";
		}		
		cout << endl;
	}	
}
