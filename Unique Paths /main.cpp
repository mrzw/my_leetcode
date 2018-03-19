#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> a(m, vector<int>(n, 0));
        for(int i=0; i<m; i++) {
        	for(int j=0; j<n; j++) {
        		if(i==0 || j==0) {
        			a[i][j] = 1;
        		}else {
        			a[i][j] = a[i-1][j] + a[i][j-1];
        		}
        	}
        }
        return a[m-1][n-1];
    }
};
int main(int argc, char** argv) {
	Solution s;
	int result = s.uniquePaths(2,3);
	cout << result << endl;
	return 0;
}
