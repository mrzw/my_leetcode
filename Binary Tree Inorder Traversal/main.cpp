#include <iostream>
#include <vector>
#include <stack>
using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};
class Solution {
public:
    // 非递归
    vector<int> inorderTraversal1(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        while(!s.empty() || root!=NULL) {
            if(root!=NULL) {
                s.push(root);
                root = root->left;
            } else {
                root = s.top();
                s.pop();
                result.push_back(root->val);
                root = root->right;
            }
        }
        return result;
    }

    // 递归
    std::vector<int> inorderTraversal(TreeNode *root)
    {
        std::vector<int> v;
        inorderTraversal(root, v);
        return v;
    }
    void inorderTraversal(TreeNode *root, std::vector<int> &v)
    {
        if (root == NULL) return;
        inorderTraversal(root->left, v);
        v.push_back(root->val);
        inorderTraversal(root->right, v);
    }
};

int main(int argc, char** argv) {

    return 0;
}