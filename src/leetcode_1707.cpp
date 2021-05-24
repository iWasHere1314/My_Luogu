#define MU_DEBUG

#include<bits/stdc++.h>
using namespace std;

class tree{
public:
    tree( ) = default;
    //~tree(){
    //    delete left;
    //    delete right;
    //}
    void insert( int val  ){
        tree *cur = this;
        cur->min_val = min( cur->min_val, val );
        for( int i=31; i>=0; --i ){
            int temp = val&(1<<i);
            if( temp ){
                if( !cur->right ){
                    cur->right = new tree();
                }
                cur = cur->right;
                cur->min_val = min( cur->min_val, val );
            }
            else{
                if( !cur->left ){
                    cur->left = new tree();
                }
                cur = cur->left;
                cur->min_val = min( cur->min_val, val );
            }
        }
    }
    int find( int val, int m ){
        auto cur = this;
        if( cur->min_val > m ){
            return -1;
        }
        int res=0;
        for( int i=31; i>=0; --i ){
            int mask = 1<<i;
            int bit_val = val&mask;
            if( bit_val ){
                if( cur->left ){
                    cur = cur->left;
                }
                else if( cur->right && res + mask <= m && cur->right->min_val <= m ){
                    cur = cur->right;
                    res += mask ;
                }
                else{
                    return -1;
                }
            }
            else{
                if( cur->right && res + mask <= m && cur->right->min_val <= m ){
                    cur = cur->right;
                    res += mask ;
                }
                else if( cur->left  ){
                    cur = cur->left;
                }
                else{
                    return -1;
                }
            }
        }
        return val ^ res;
    }
private:
    tree *left=nullptr, *right=nullptr;
    int min_val=INT32_MAX;
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        tree trie;
        for( auto &i: nums ){
            trie.insert( i );
        }
        size_t sz = queries.size();
        vector<int> res( sz );
        for( size_t i=0; i<sz; ++i ){
            res[i] = trie.find( queries[i][0], queries[i][1] );
        }
        return res;
    }
};

int main(){
    vector<int> nums = {0,1,2,3,4};
    vector<vector<int>> queries= {{3,1},{1,3},{5,6}};
    Solution sl;
    sl.maximizeXor( nums, queries );
}