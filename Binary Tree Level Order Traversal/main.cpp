#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        queue<TreeNode*> q;
        vector< vector<int> > vv;
        vector<int> v;
        if (root){
            v.push_back(root->val);
            vv.push_back(v);
        }
        q.push(root);
        vector<TreeNode*> vt;
        while(!q.empty()){
            TreeNode *p = q.front();
            q.pop();
            vt.push_back(p);
            if ( !p ) {
                continue;
            }
            q.push(p->left);
            q.push(p->right);
        }
        int step = 2;
        for (int i=1,j=1; i<vt.size(); i=j ){
            v.clear();

            int cnt=0;
            for (j=i; j<i+step && j<vt.size(); j++){
                if (vt[j]) {
                    v.push_back(vt[j]->val);
                    cnt += 2;
                }
            }
            step = cnt;
            if (!v.empty()) {
                vv.push_back(v);
            }
        }
        return vv;
    }
};