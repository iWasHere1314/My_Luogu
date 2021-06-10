#define MY_DEBUG

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        const long long MOD = 1e9 + 7;
        int work_sz = (int)group.size();
        vector< vector< long long> > dp( n+1, vector<long long>( minProfit+1, 0 ) );
        for( int i=0; i<=n; ++i ){
            dp[i][0] = 1;
        }
        for( int i=group[0]; i<=n; ++i ){
            auto &t = dp[i];
            int p = profit[0];
            int j_e = min( profit[0], minProfit );
            for( int j=0; j<=j_e; ++j ){
                t[j] += 1;
                #ifdef MY_DEBUG
                    printf( "i=%d, j=%d, k=%d, dp=%d\n", 0, i, j, t[j] );
                #endif
            }
        }
        for( int i=1; i< work_sz; ++i ){
            int g = group[i]; 
            int p = profit[i];
            for( int j=n; j>=g; --j ){
                for( int k=minProfit; k>=p ; --k ){
                    dp[j][k] += dp[j-g][k-p];
                    dp[j][k] %= MOD;
                    #ifdef MY_DEBUG
                        printf( "i=%d, j=%d, k=%d, dp=%d\n", i, j, k, dp[j][k] );
                    #endif
                }
                for( int k=min(p-1,minProfit); k>=0; --k ){
                    dp[j][k] += dp[j-g][0];
                    dp[j][k] %= MOD;
                    #ifdef MY_DEBUG
                        printf( "i=%d, j=%d, k=%d, dp=%d\n", i, j, k, dp[j][k] );
                    #endif
                }
            }
        }
        return (int)dp[n][minProfit];
    }
};