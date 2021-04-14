#include<bits/stdc++.h>
using namespace std;
/* 此题思路真的很奇妙啊 */
const int MAX_N = 2E4+10;
const int MAX_M = 2E4+10;
int dp[2*MAX_M];
int par[MAX_N];
int cnt[MAX_N];
int n, m, k, par_num;
int u_find( int x ){
    if( x == par[x] ){
        return x;
    }
    return par[x] = u_find(par[x]);
}
bool unite( int x, int y ){
    x = u_find(x);
    y = u_find(y);
    if( x == y ){
        return false;
    }
    if( x<y ){
        par[y] = x;
        cnt[x] += cnt[y];
        cnt[y] = 0;
    }
    else{
        par[x] = y;
        cnt[y] += cnt[x];
        cnt[x] = 0;
    }
    return true;
}
int main(){
    scanf("%d %d %d", &n, &m, &k );
    par_num = n;
    fill( cnt+1, cnt+n+1, 1 );
    for( int i=1; i<=n; ++i ){
        par[i] = i;
    }
    int x, y;
    for( int i=0; i<k; ++i ){
        scanf("%d %d", &x, &y);
        if( unite(x,y) ){
            --par_num;
        }
    }
    int i=0,j=-1;
    while( i<=n ){
        if( cnt[i] != 0 && j != -1 ){
            swap(cnt[i], cnt[j] );
            ++j;
        }
        else if( cnt[i] == 0 && j == -1 ){
            j = i;
        }
        ++i;
    }
    for( i=2*m; i>=cnt[0]; --i ){
        dp[i] = cnt[0];
    }
    for( i=1; i<par_num; ++i ){
        for( j=2*m; j>=cnt[i]; --j ){
            dp[j] = max( dp[j], dp[j-cnt[i]] + cnt[i] );
        }
    }
    int res=8e4;
    for( i=0; i<=2*m; ++i ){
        if( abs(dp[i]-m) < abs( res-m ) ){
            res = dp[i];
        }
    }
    printf("%d\n", res );

    return 0;
}

/*
5 3 4
1 2
1 3
1 4
1 5

5 1 4
1 2
1 3
1 4
1 5

5 3 4
2 1
3 2
3 4
4 5

6 6 0
*/