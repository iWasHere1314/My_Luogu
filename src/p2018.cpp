#include<bits/stdc++.h>
using namespace std;
const int scale = 1000 + 20;
struct person{ 
    vector<int> connect;
} ps[scale];
int n;
vector<int> res;
int min_res = scale;
int spend[scale][scale];

int find_res( int speak, int listen ){
    if( speak != 0 && spend[speak][listen] != -1 ){
        return spend[speak][listen];
    }
    int ret = 1;
    int size = ps[listen].connect.size();
    vector<int> tm_vec;
    for( int i=0 ; i<size; ++i ){
        auto next_listen = ps[listen].connect[i];
        if( next_listen != speak ){
            auto cur_time = find_res( listen, next_listen );
            tm_vec.emplace_back(cur_time);
        }
    }
    sort(tm_vec.begin(), tm_vec.end(), greater<int>() );
    size = tm_vec.size();
    int pl_time = 0;
    for( int i=0; i<size; ++i ){
        if( i==0 ){
            ret += tm_vec[i];
        }
        else{
            if( pl_time < 0 ){
                pl_time = 0;
            }
            ret += tm_vec[i] > pl_time ? tm_vec[i] - pl_time: 0;
        }
        pl_time = max( pl_time-1, tm_vec[i]-1 );
    }
    // printf(" [%d,%d] %d\n",speak, listen, ret );
    return spend[speak][listen] = ret;
}

int main(){
    scanf("%d",&n);
    for( int i=1; i<=n; ++i ){
        fill( spend[i]+1, spend[i]+n+1, -1 );
    }
    for( int i=2; i<=n; ++i ){
        int num;
        scanf( "%d", &num );
        ps[i].connect.emplace_back(num);
        ps[num].connect.emplace_back(i);
    }
    auto cmp = []( const int &a, const int &b ) -> bool
        { return ps[a].connect.size() > ps[b].connect.size() ;};
    for( int i=1; i<=n; ++i ){
        auto temp = find_res( 0, i );
        if( temp < min_res ){
            min_res = temp;
            res.clear();
            res.emplace_back(i);
        }
        else if( temp == min_res ){
            res.emplace_back(i);
        }
    }
    printf("%d\n", min_res );
    int size = res.size();
    for( int i=0; i<size; ++i ){
        printf("%d", res[i] );
        if( i != size-1 ){
            printf(" ");
        }
    }
    return 0;
}
/*
 7
 1
 1
 2
 2
 3
 3

 13
 1
 1
 1
 2
 2
 2
 3
 3
 3
 4
 4
 4

21
1
1
1
1
2
2
2
2
3
3
3
3
4
4
4
4
5
5
5
5

*/