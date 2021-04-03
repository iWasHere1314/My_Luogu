#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 2*10E6+1;
int dp[MAX_N];
int lg[MAX_N];
int seq[MAX_N];
int n, m;

int main(){
    scanf("%d %d", &n, &m );
    for( int i=0; i<n; ++i ){
        scanf("%d", seq+i );
    }
    lg[1] = 0;
    for( int i=2; i<n; ++i ){
        lg[i] = lg[i/2] + 1;
    }
    for( int i=0; i<n; ++i ){
        dp[i] = seq[i];
    }
    int exp_m  = lg[m];
    for( int i=1, h_len = 1, len=2; i<=exp_m; ++i, h_len*=2, len*=2 ){
        for( int j=0; j+len<=n; j++ ){
            dp[j] = min( dp[j], dp[j+h_len] );
        }
    }
    printf("0\n");
    int mi = 0x7fffffff;
    for( int i=1; i<m ;++i ){
        printf("%d\n", mi = min(mi,seq[i-1]) );
    }
    for( int i=m; i<n; ++i ){
        int r=i, l= r-m;// l = r-1-m+1;
        printf("%d\n", min( dp[l], dp[r-(1<<exp_m)] ) );
    }
    return 0;
}