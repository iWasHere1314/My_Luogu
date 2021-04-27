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
    int rangeSumBST(TreeNode* root, int low, int high) {
        TreeNode *cur = root;
        stack<TreeNode*> stk;
        int res=0;
        while( cur || stk.size() ){
            while( cur ){
                stk.push( cur );
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            int temp_val = cur->val;
            if( temp_val>high ){
                break;
            }
            else if( temp_val >= low) {
                res += temp_val;
            }
            cur = cur->right;
        }
        return res;
    }
};