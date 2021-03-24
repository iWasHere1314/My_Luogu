// push_back的时间可以优化
// 建议改用邻接矩阵
#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 10E3+10;
const int MAX_M = 10E5+10;
const long long INF = 10E9;
long long dis[2][MAX_N];
struct edge
{
    int index;
    long long cost;
    edge( int i, long long c): index(i), cost(c) {};
};

vector<edge> g_map_to[MAX_N];
vector<edge> g_map_back[MAX_N];
int n, m;
void dijkstra( const decltype(g_map_to) & g_map ){
    int dir = g_map == g_map_to ? 0: 1;
    priority_queue< pair<long, int> > que;
    fill( dis[dir], dis[dir]+n+1, INF );
    dis[dir][1] = 0;
    que.push( make_pair( 0, 1) );
    while( que.size() ){
        auto cur = que.top();
        que.pop();
        if( cur.first > dis[dir][cur.second] ){
            continue;
        }
        for( const auto& i: g_map[cur.second] ){
            if( dis[dir][i.index] > dis[dir][cur.second] + i.cost ){
                dis[dir][i.index] = dis[dir][cur.second] + i.cost;
                que.emplace( dis[dir][i.index], i.index );
            }
        }
    }
}

int main(){
    scanf("%d %d",&n, &m );
    for( int i=0; i<m; ++i ){
        int from,to;
        long long cost;
        scanf("%d %d %lld", &from, &to, &cost);
        g_map_to[from].emplace_back(to, cost ) ;
        g_map_back[to].emplace_back(from, cost);
    }
    dijkstra(g_map_to);
    dijkstra(g_map_back);
    long long res=0;
    for( int i=2; i<=n; ++i ){
        res += dis[0][i] + dis[1][i];
    }
    printf("%lld\n", res);

    return 0;
}
