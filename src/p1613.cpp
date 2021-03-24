#include<bits/stdc++.h>
using namespace std;
const int scale = 50 + 10;
const unsigned long long INF = LONG_LONG_MAX/scale;
bool one_second[65][scale][scale]={false};
unsigned long long dis[scale];
bool used[scale];
unsigned long long g_map[scale][scale];
int n, m;

void get_one_second(){
    for( int k=2; k<=64; ++k ){
        for( int i=1; i<=n; ++i ){
            for( int j=1; j<=n; ++j ){
                for( int l=1; l<=n; ++l ){
                    if( one_second[k][i][j] |= ( one_second[k-1][i][l] & one_second[k-1][l][j] ) ){
                        g_map[i][j] = 1;
                    }
                }
            }
        }
    }
}
void dijkstra(){
    fill( dis+1, dis+1+n, INF );
    memset( used, false, sizeof(used) );
    dis[1] = 0;
    int cur;
    while( true ){
        cur = -1;
        for( int pre=1; pre<=n; ++pre ){
            if( !used[pre] &&( cur==-1 || dis[pre]<dis[cur] ) ){
                cur = pre;
            }
        }
        if( cur == -1){
            break;
        }
        used[cur] = true;
        for( int to=1; to<=n; ++to ){
            dis[to] = min( dis[to], dis[cur]+g_map[cur][to] );
        }
    }
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; ++i ){
        for( int j=1; j<=n; ++j ){
            g_map[i][j] = INF;
        }
    }
    for( int i=1; i<=m; ++i ){
        int from, to;
        scanf("%d %d", &from, &to );
        g_map[from][to] = 1;
        one_second[1][from][to] = true;
    }
    get_one_second();
    dijkstra();
    printf("%llu\n", dis[n] );

    return 0;
}