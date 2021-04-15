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
    int rob(TreeNode* root) {
        return max( get_val(root, 0, 0) , get_val(root, 1, 0 ) );
    }
private:
    int get_val( TreeNode *cur, int used, unsigned long long index){
        if( dp.find(cur)!=dp.end() ){
            if( dp[cur][used] != -1  ){
                return dp[cur][used];
            }
        }
        else{
            dp[cur] = vector<int>(2,-1);
        }
        int res = used? cur->val: 0;
        if( used ){
            res += ( cur->left? get_val(cur->left, 0 , index*2 ): 0 ) + ( cur->right? get_val(cur->right, 0 , index*2+1): 0 );
        }
        else{
            res += ( cur->left? max( get_val(cur->left, 1, index*2 ) , get_val(cur->left, 0 , index*2 ) ): 0 )
                + ( cur->right? max( get_val(cur->right, 1, index*2+1 ) , get_val(cur->right, 0, index*2+1) ): 0 );
        }
        return dp[cur][used]=res;
    }
    unordered_map<TreeNode* , vector<int> > dp;
};