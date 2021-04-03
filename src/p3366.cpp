#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 5000+10;
const int MAX_M = 2*10E5 + 10;
int edge_num = 0;
int first_dege[MAX_N], next_edge[2*MAX_M], edge_node[2*MAX_M], edge_cost[2*MAX_M];
bool used[MAX_N];
int n, m;
priority_queue< pair<int, pair<int, int> >, deque<pair<int, pair<int, int> >  > ,  greater<pair<int, pair<int, int> > > > que;
inline void add_edge( int x, int  y, int cost ){
    ++edge_num;
    next_edge[edge_num] = first_dege[x];
    first_dege[x] = edge_num;
    edge_node[edge_num] = y;
    edge_cost[edge_num] = cost;
    ++edge_num;
    next_edge[edge_num] = first_dege[y];
    first_dege[y] = edge_num;    
    edge_node[edge_num] = x;
    edge_cost[edge_num] = cost;
}
inline void push_edge( int node, int cur_edge ){
    while( cur_edge ){
        int nxt = edge_node[cur_edge];
        if( !(used[node] && used[nxt]) ){
            que.push( {edge_cost[cur_edge], {node, nxt} } );
        }
        cur_edge = next_edge[cur_edge];
    }
}
int main(){
    scanf("%d %d", &n, &m );
    for( int i=0; i<m; ++i ){
        int x, y, c;
        scanf("%d %d %d", &x, &y, &c );
        add_edge(x, y, c); 
    }
    //begin
    used[1] = true;
    int linked = 1;
    push_edge( 1, first_dege[1] );
    int res = 0;

    while( que.size() ){
        auto temp = que.top();
        int from = temp.second.first;
        int to = temp.second.second;
        que.pop();
        if( used[from] && used[to ] ){
            continue;
        }
        res += temp.first;
        int nxt = used[from] ? to: from;
        used[nxt] = true;
        ++linked;
        push_edge( nxt, first_dege[nxt] );
    }
    //end
    if( linked == n ){
        printf("%d\n", res );
    }
    else{
        printf("orz\n");
    }

    return 0;
}