#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int res = 1e6;
        int pre = -1e5;
        stack<TreeNode*> stk;
        TreeNode* node = root; 
        while( node || stk.size() ){
            while( node ){
                stk.emplace( node );
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            res = min( res, abs(node->val-pre) );
            pre = node->val;
            node = node->right;
        }
        return res;
    }
};