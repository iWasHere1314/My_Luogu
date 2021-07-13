#include<bits/stdc++.h>
using namespace std;

struct node{
    int x;
    int index;
    int h;
    bool l;
    node() = default;
    node( int a, int b, int c, bool d ): x(a), index(b), h(c), l(d){};
};


        
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int sz = buildings.size();
        vector< node > bd( sz*2 );
        for( int i=0; i<sz; ++i ){
            bd[i*2] = node( buildings[i][0], i, buildings[i][2], true );
            bd[i*2+1] = node( buildings[i][1], i, buildings[i][2], false );
        }
        auto f = [&]( const node &a, const node &b )->bool{
            if( a.x == b.x ){
                if( a.l && b.l ){
                    return a.h > b.h;
                }
                else if( !a.l && !b.l ){
                    return a.h <= b.h;
                }
                else{
                    return a.l;
                }
            }
            return a.x <= b.x;
        };
        sort( bd.begin(), bd.end(), f );
        multimap< int, int, greater<int> > height;
        vector< vector<int> > res;
        int mx = 0;
        for( auto i: bd ){
            if( i.l ){
                if( mx < i.h ){
                    mx = i.h;
                    vector<int> temp{ i.x, mx };
                    res.emplace_back( temp );
                }
                height.emplace( i.h, i.index );
            }
            else{
                auto rang = height.equal_range( i.h );
                auto b = rang.first;
                auto e = rang.second;
                while( b != e ){
                    if( b->second == i.index ){
                        height.erase(b);
                        break;
                    }
                    ++b;
                }
                if( i.h == mx ){
                    auto it = height.begin();
                    if( it != height.end() ){
                        int num = it->second;
                        mx = it->first;
                        if( i.h > mx && i.x < buildings[num][1] ){
                            vector<int> temp{ i.x, mx };
                            res.emplace_back( temp );
                        } 
                    }   
                    else{
                        mx = 0;
                        vector<int> temp{ i.x, mx };
                        res.emplace_back( temp );
                    }
                }
            }
        }
        return res;
    }
};

/* int main(){
    vector<vector<int>> buildings;
    Solution sl;
    buildings = {{0,3,3},{1,5,3},{2,4,3},{3,7,3}};
    sl.getSkyline( buildings );
    return 0;
} */