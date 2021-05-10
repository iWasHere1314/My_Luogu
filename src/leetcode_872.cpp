#define My
#ifdef My
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> res1, res2;
        dfs( root1, res1 );
        dfs( root2, res2 );
        return res1 == res2;
    }
private:
    void dfs( TreeNode* root, vector<int> &res ){
        bool node = true;
        if( root->left ){
            node = false;
            dfs( root->left, res );
        }
        if( root->right ){
            node =false;
            dfs( root->right, res );
        }
        if( node ){
            res.emplace_back( root->val );
        }
    }
};