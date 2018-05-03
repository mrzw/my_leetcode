// https://github.com/pezy/LeetCode/tree/master/077.Subsets
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>> &board, string &word, int idx, int row,
               int col, vector<vector<int>> &mask) {
        int i = row;
        int j = col;
        if (board[i][j] == word[idx] && mask[i][j]==0 ) {
            mask[i][j] = 1;
            if (idx + 1 == word.size()) return true;
            idx++;
            if ((i + 1 < board.size() && exist(board, word, idx, i + 1, j, mask)) ||
                (i > 0 && exist(board, word, idx, i - 1, j, mask)) ||
                (j + 1 < board[i].size() && exist(board, word, idx, i, j + 1, mask)) ||
                (j > 0 && exist(board, word, idx, i, j - 1, mask))) {
                return true;
            }
            mask[i][j] = 0;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string& word) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>> mask(row, vector<int>(col, 0));
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(board[i][j]==word[0]) {
                    vector<vector<int>> m = mask;
                    if(exist(board, word, 0, i, j, m)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
int main(int argc, char** argv) {
    vector<vector<char>> a{};
    string word = "";
    Solution s;
    bool result = s.exist(a, word);
    cout << result << endl;

    return 0;
}
