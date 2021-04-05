#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1000000+10;
const int MAX_M = 2000000+10;
const int MOD = 100000 + 3;
enum status{ none, in_que, sure };
int edge_num=0;
int first_edge[MAX_N], next_edge[MAX_M*2], edge_node[MAX_M*2];
int res[MAX_N];
int len[MAX_N];
int n, m;

void add_edge( int x, int y ){
    ++edge_num;
    next_edge[edge_num] = first_edge[x];
    edge_node[edge_num] = y;
    first_edge[x] = edge_num;
    ++edge_num;
    next_edge[edge_num] = first_edge[y];
    edge_node[edge_num] = x;
    first_edge[y] = edge_num;  
}

int main(){
    scanf("%d %d", &n, &m );
    for( int i=0; i<m; ++i ){
        int x, y;
        scanf("%d %d", &x, &y);
        add_edge( x, y );
    }
    fill( len+1, len+1+n, 0x7fffffff );
    queue<int> que;
    res[1] = 1;
    len[1] = 1;
    que.push(1);
    while( que.size() ){
        int cur_node = que.front();
        que.pop();
        int cur_edge = first_edge[cur_node];
        while( cur_edge ){
            int next_node = edge_node[cur_edge];
            if( len[ next_node ] == len[cur_node]+1 || len[ next_node ] == 0x7fffffff ){
                res[ next_node ] += res[ cur_node ];
                res[ next_node ] %= MOD;
                if( len[ next_node] == 0x7fffffff ){
                    len[ next_node ] = len[cur_node] + 1;
                    que.push( next_node );
                }
            }
            cur_edge = next_edge[ cur_edge ];
        }
    }
    for( int i=1; i<=n; ++i ){
        printf("%d\n", res[i] );
    }
    return 0;
}