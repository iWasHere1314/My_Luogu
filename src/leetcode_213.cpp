#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        /* 分两种情况，第一家偷，第一家不偷 */
        int sz = nums.size();
        int dp[2], pre_0, pre_1, res=0;
        //case 1: 第一家一定被偷
        dp[0] = -1;
        dp[1] = nums[0];
        for( int i=1; i<sz-1; ++i ){
            pre_0 = dp[0];
            pre_1 = dp[1];
            dp[0] = max( pre_0, pre_1 );
            dp[1] = pre_0+nums[i];
        }
        res = max( res, max( dp[0], dp[1] ) );
        //case 2：第一家一定不被被偷
        dp[0] = 0;
        dp[1] = -1;
        for( int i=1; i<sz; ++i ){
            pre_0 = dp[0];
            pre_1 = dp[1];
            dp[0] = max( pre_0, pre_1 );
            dp[1] = pre_0+nums[i];
        }
        res = max( res, max( dp[0], dp[1] ) );
        
        return res;
    }
};