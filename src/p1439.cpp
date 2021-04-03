#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 10E5 + 10;
const int INF = 0x7fffffff;
int dp[MAX_N], seq_a[MAX_N], seq_b[MAX_N];
int n;
int len = 0;
map<int, int> loc;
int main(){
    scanf("%d", &n );
    for( int i=0; i<n; ++i ){
        scanf("%d", seq_a+i );
    }
    for( int i=0; i<n; ++i ){
        scanf("%d", seq_b+i );
        loc[seq_b[i]] = i;
    }
    for( int i=0; i<n; ++i ){
        int cur_loc = loc[seq_a[i]];
        auto index = lower_bound( dp+1, dp+1+len , cur_loc );
        if( index == dp+1+len ){
            dp[++len] = cur_loc;
        }
        else{
            *index = cur_loc;
        }
    }
    printf("%d\n", len );

    return 0;
}