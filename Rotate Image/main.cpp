#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i<n/2; i++) {
        	int low=i, high=n-i-1;
        	for(int j=low; j<high; j++) {
        		int temp;
        		temp = matrix[i][j];
        		// left to top 
            	matrix[i][j] = matrix[n-j-1][i];
            	// bottom to left
            	matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
            	// right to bottom
            	matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
            	// top to right
				matrix[j][n-i-1] = temp;
        	}
        }
    }
};

int main(int argc, char** argv) {
	vector<vector<int> > a{{1,2,3},{4,5,6},{7,8,9}};
	Solution s;
	s.rotate(a);
	for(auto i:a) {
		for(auto j:i) {
			cout << j << " ";			
		}
		cout << endl;
	}		
}
