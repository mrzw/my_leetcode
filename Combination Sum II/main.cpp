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
			if(i>start && candidates[i]==candidates[i-1]) { //he solution set must not contain duplicate combinations.
				continue;
			}
			solution.push_back(candidates[i]);
			dfs(candidates, i+1, target-candidates[i], solution, result);
			solution.pop_back();
		}
	}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
	vector<int> v{10, 1, 2, 7, 6, 1, 5};
	Solution s;
	vector<vector<int> > vv = s.combinationSum2(v, 8);
	for(auto &i:vv) {
		for(auto j:i) {
			cout << j << " ";
		}		
		cout << endl;
	}	
}
