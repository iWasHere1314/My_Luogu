#define MY_DEBUG

#include<bits/stdc++.h>
using namespace std;

#ifdef MY_DEBUG
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if( root->val == x || root->val == y ){
            return false;
        } 
        queue<TreeNode*> q;
        q.push( root );
        q.push( nullptr );
        int if_find = 0;
        bool son_x = false;
        bool son_y = false;
        while( q.size() ){
            son_x = false;
            son_y = false;
            TreeNode * cur = q.front();
            q.pop();
            if( !cur ){
                if( q.size() ){
                    q.push( nullptr );
                }
                if_find = 0;
                continue;
            }
            if(  cur->left ){
                q.push( cur->left );
                son_x |= cur->left->val == x;
                son_y |= cur->left->val == y;
            }
            if( cur->right ){
                q.push( cur->right );
                son_x |= cur->right->val == x;
                son_y |= cur->right->val == y;
            }
            if( son_x && son_y ){
                return false;
            }
            else if( son_x || son_y ){
                if_find += 1;
            }
            if( if_find == 2 ){
                return true;
            } 
        }
        return false;
    }
};