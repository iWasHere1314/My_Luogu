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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *ret;
        TreeNode *org_cur=root, *new_cur;
        stack<TreeNode* > stk;
        while( org_cur || stk.size() ){
            while( org_cur  ){
                stk.push( org_cur  );
                org_cur = org_cur->left;
            }
            org_cur = stk.top();
            stk.pop();
            if( !ret ){
                ret = new TreeNode( org_cur->val );
                new_cur = ret;
            }
            else{
                auto temp = new TreeNode( org_cur->val );
                new_cur->right = temp;
                new_cur = temp;
            }
            org_cur = org_cur->right;
        }
        return ret; 
    }
};