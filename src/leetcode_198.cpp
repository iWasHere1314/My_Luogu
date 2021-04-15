#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = nums.size();
        int dp[2];
        dp[0] = 0;
        dp[1] = nums[0];
        for( int i=1; i<sz; ++i ){
            int pre_0 = dp[0], pre_1 = dp[1];
            dp[0] = max( pre_0, pre_1 );
            dp[1] = pre_0+nums[i];
        }
        return max( dp[0], dp[1] );
    }
};