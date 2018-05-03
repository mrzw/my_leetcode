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
    //方法1：递归
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
    bool isValidBST(TreeNode* root, long minNum, long maxNum) {
        if(!root) return true;
        if(root->val <= minNum || root->val >= maxNum) return false;
        return isValidBST(root->left, minNum, root->val) && isValidBST(root->right, root->val, maxNum);
    }
    //方法2：中序遍历,判断序列是否从小到大
    void inorderTraversal(TreeNode *root, std::vector<int> &v)
    {
        if (!root) return;
        inorderTraversal(root->left, v);
        v.push_back(root->val);
        inorderTraversal(root->right, v);
    }
    bool isValidBST1(TreeNode* root) {
        vector<int> a;
        inorderTraversal(root, a);
        int n = a.size();
        for(int i=0; i<n-1; ++i) {
            if(a[i]>=a[i+1]) {
                return false;
            }
        }
        return true;
    }
    // 创建二叉树
    TreeNode* createTree(int a[], int n)
    {
        if (n<=0) return NULL;

        TreeNode **tree = new TreeNode*[n];

        for(int i=0; i<n; i++) {
            if (a[i]==0 ){
                tree[i] = NULL;
                continue;
            }
            tree[i] = new TreeNode(a[i]);
        }
        int pos=1;
        for(int i=0; i<n && pos<n; i++) {
            if (tree[i]){
                tree[i]->left = tree[pos++];
                if (pos<n){
                    tree[i]->right = tree[pos++];
                }
            }
        }
        return tree[0];
    }
//    int b[]={4,2,6,1,7,5,7};
//    TreeNode* root = createTree(b, sizeof(b)/sizeof(int));
};