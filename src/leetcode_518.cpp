#define MY_DEBUG

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int sz = (int)coins.size();
        vector<int>dp( amount+1 , 0 );
        for( int i=0, val=coins[0]; i<=amount; ++i ){
            if( i%val == 0 ){
                dp[i] = 1;
                #ifdef MY_DEBUG
                    printf( "i=%d, j=%d, res=%d\n",0,i,dp[i] );
                #endif
            }
        }
        
        for( int i=1; i<sz; ++i ){
            for( int j=amount, val=coins[i]; j>=0; --j ){
                int res = dp[j];
                for( int k=j-val; k>=0; k-=val ){
                   res += dp[k];
                }
                dp[j] = res;
                #ifdef MY_DEBUG
                    printf( "i=%d, j=%d, res=%d\n",i,j,dp[j] );
                #endif
            }
        }
        return dp[amount];
    }
};