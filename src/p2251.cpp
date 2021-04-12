#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1000000+10;
int n, m;
deque<pair<int, int > > q;
inline void q_push_m( int loc, int num ){
    if( 0 == q.size() ){
        q.emplace_back( loc, num );
        return;
    }
    else if( q.back().second<num ){
        q.emplace_back( loc, num );
        return;
    }
    while( q.size() && q.back().second>=num ){
        q.pop_back();
    }
    q.emplace_back( loc, num );
    return;
}
inline void q_push_n( int loc, int num ){
    if( q.size() && loc-q.front().first+1>m ){
        q.pop_front();
    }
    q_push_m( loc, num );
}

int main(){
    scanf("%d %d", &n, &m );
    int temp;
    int i=0;
    while( i<m ){
        scanf("%d", &temp );
        q_push_m( i, temp );
        ++i;
    }
    printf("%d\n", q.front().second );
    while( i<n ){
        scanf("%d", &temp );
        q_push_n( i, temp );
        printf("%d\n", q.front().second );
        ++i;
    }
    return 0;
}
/*

10 5
1 2 3 4 5 6 7 8 9 10

10 5
10 9 8 7 6 5 4 3 2 1
*/