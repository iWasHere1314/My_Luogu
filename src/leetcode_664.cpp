#define MY_DEBUG
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int strangePrinter(string s) {
        size_t sz = s.size();
        vector< vector<int> > dp( sz, vector<int>( sz, INT32_MAX ) );
        for( size_t i=0; i<sz; ++i ){
            dp[i][i] = 1;
            #ifdef MY_DEBUG
                printf("i=%lu, j=%lu, res=%d\n",i,i,1);
            #endif
        }
        for( size_t dis = 2; dis<=sz; ++dis ){
            for( size_t i=0, j; (j=i+dis-1)<sz; ++i ){
                char target_c = s[j];
                int res = dp[i][j-1] + 1;
                for( size_t k=i; k<=j-1; ++k ){
                    if( s[k] == target_c ){
                        int temp = dp[k][j-1];
                        if( k>i ){
                            temp += dp[i][k-1];
                        }
                        res = min( temp, res );
                    }
                }
                dp[i][j] =  res;
                #ifdef MY_DEBUG
                    printf("i=%lu, j=%lu, res=%d\n",i,j,dp[i][j] );
                #endif
            }
        }
        return dp[0][sz-1];

    }
};

#ifdef MY_DEBUG
int main(){
    Solution sl;
    sl.strangePrinter( "aaabbb" );
    system("sleep 1h");
}
#endif