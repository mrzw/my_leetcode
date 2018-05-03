#include <iostream>
#include <vector>
using namespace std;
// 二叉搜索树有个性质，就是左边的数都比根小，右边的数都比根大   卡特兰数
// https://www.cnblogs.com/grandyang/p/4299608.html
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};

int main(int argc, char** argv) {

    return 0;
}