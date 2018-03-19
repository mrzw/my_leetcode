#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size(); i++) {
        	for(int j=0; j<grid[i].size(); j++) {
        		if(i==0 && j==0) continue;
        		if(i==0) grid[i][j] += grid[i][j-1];
        		else if(j==0) grid[i][j] += grid[i-1][j];
        		else grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
        	}
        }
        return grid[grid.size()-1][grid[0].size()-1];
    }
};
int main(int argc, char** argv) {
	Solution s;
	vector<vector<int>> a{{1,3,1},{1,5,1},{4,2,1}};
	int result = s.minPathSum(a);
	cout << result << endl;
	return 0;
}
