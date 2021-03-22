#include<bits/stdc++.h>
using namespace std;
const int MAX = 10E8;
const int MIN = 0;
struct cow{
    int max_h = MIN;
    int min_h = MAX;
};
vector<cow> cows;
int n, q, real_size;
void update( int index, int height );
pair<int, int> query( int f_s, int f_e, int index, int s, int e );
void init( );

int main(){
    scanf("%d %d", &n, &q );
    init();
    for( int i=0; i<n; ++i ){
        int temp;
        scanf("%d", &temp);
        update( i, temp );
    }
    for( int i=0; i<q; ++i ){
        int f_s, f_e;
        scanf("%d %d", &f_s, &f_e );
        auto res = query(f_s-1, f_e, 0, 0, real_size);
        printf("%d\n", res.first-res.second);
    }

    return 0;
}

void update( int index, int height ){
    index += real_size-1;
    cows[index].max_h = cows[index].min_h = height;
    while( index>0 ){
        index = ( index - 1 ) / 2;
        cows[index].max_h = max( cows[index*2+1].max_h, cows[index*2+2].max_h ); 
        cows[index].min_h = min( cows[index*2+1].min_h, cows[index*2+2].min_h );
    }
}


pair<int, int> query( int f_s, int f_e, int index, int s, int e ){
    if( f_e<=s || f_s>=e ){
        return make_pair( MIN, MAX );
    }
    else if( f_s<=s && f_e>=e ){
        return make_pair( cows[index].max_h, cows[index].min_h );
    }
    else{
        auto res1 = query( f_s, f_e, index*2+1, s, (s+e)/2 );
        auto res2 = query( f_s, f_e, index*2+2, (s+e)/2, e );
        return make_pair( max( res1.first, res2.first ), min( res1.second, res2.second ) );
    }
}

void init( ){
    real_size = 1;
    while( real_size < n ){
        real_size *= 2;
    }
    cows.resize( 2*real_size );
}