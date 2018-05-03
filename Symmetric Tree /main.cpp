#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return (p->val == q->val) &&
               isSymmetric(p->left, q->right) &&
               isSymmetric(p->right, q->left);
    }
};