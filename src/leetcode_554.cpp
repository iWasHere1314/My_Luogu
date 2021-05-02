#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map< int, int> mp;
        int res=0;
        for( auto &i: wall ){
            int cur = 0;
            size_t sz = i.size()-1;
            for( size_t j=0; j<sz; ++j ){
                cur += i[j];
                auto temp = mp.emplace( cur, 0 );
                int temp_res = (++temp.first->second) ;
                if( temp_res > res ){
                    res = temp_res;
                }
            }
        }
        return wall.size() - res;
    }
};