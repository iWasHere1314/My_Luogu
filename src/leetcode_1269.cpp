#define MY
#ifdef MY
#include<bits/stdc++.h>
using namespace std;
#endif
class Solution {
public:
    int numWays(int steps, int arrLen) {
        size_t sts = steps, al = arrLen;
        size_t sz = sts+1<al? sts+1: al;
        vector< vector< long long > > 
            dp( sz, vector<long long>(sts+1, 0 ) );
        dp[0][1] = 1;
        dp[1][1] = 1; 
        for( size_t k=2; k<=sts; ++k ){
            for( size_t i=0; i<sz; ++i ){
                long long res = dp[i][k-1];
                if( i>0 ){
                    res += dp[i-1][k-1] ;
                }
                res %= (long long )(1E9+7);
                if( i<sz-1 ){
                    res += dp[i+1][k-1];
                }
                res %= (long long )(1E9+7);
                dp[i][k] = res;
            }
        }

        return (int)( dp[0][sts] % (long long )(1E9+7) );
    }
};