#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 10E5+10;
int lg2[MAX_N]={0};
int dp[MAX_N][20];

int main(){
    int n,q;
    scanf("%d %d",&n, &q );
    for( int i=1; i<=n; ++i ){
        scanf("%d", &dp[i][0] );
    }
    for( int i=2; i<=n; ++i ){
        lg2[i] = lg2[i/2] + 1;
    }
    for( int j=1, exp=1; exp*2<=n; ++j, exp*=2 ){
        auto len = exp*2;
        for( int i=1; i+len-1<=n; ++i ){
            dp[i][j] = max( dp[i][j-1], dp[i+exp][j-1] );
        }
    }
    for( int i=0; i<q; ++i ){
        int l,r;
        scanf("%d %d", &l, &r );
        auto exp = lg2[r-l+1];
        printf("%d\n", max( dp[l][exp], dp[r-(1<<exp)+1 ][exp]) );
    }
    return 0;
}
