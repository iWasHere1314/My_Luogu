#define MY_DEBUG
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = (int)strs.size();
        vector<pair<int, int> > zero_one(sz);
        vector< vector<int> > dp( m+1, vector<int>( n+1, 0) );
        for( int i=0; i<sz; ++i ){
            int sz1 = (int)strs[i].size();
            auto &str = strs[i]; 
            int zero=0;
            int one=0;
            for( int j=0; j<sz1; ++j ){
                if( str[j] == '0' ){
                    ++zero;
                }
                else{
                    ++one;
                }
            }
            zero_one[i] = make_pair( zero, one );
        }
        for( int j=zero_one[0].first; j<=m; ++j ){
            for( int k=zero_one[0].second; k<=n; ++k ){
                dp[j][k] = 1;
                #ifdef MY_DEBUG
                    printf("i=%d,zero=%d,one=%d,res=%d\n",0,j,k,dp[j][k]);
                #endif
            }
        }
        for( int i=1; i<sz; ++i ){
            int zero = zero_one[i].first;
            int one = zero_one[i].second;
            for( int j=m; j>=zero; --j ){
                for( int k=n; k>=one; --k ){
                    dp[j][k] = max( dp[j][k], dp[j-zero][k-one] + 1 );
                    #ifdef MY_DEBUG
                        printf("i=%d,zero=%d,one=%d,res=%d\n",i,j,k,dp[j][k]);
                    #endif
                }
            }
        }
        return dp[m][n];
    }
};