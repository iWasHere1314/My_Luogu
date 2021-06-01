#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool judge( vector<long long> &presum, vector<int> &query ){
        int f_t = query[0];
        int f_d = query[1];
        long long d_c = query[2];
        long long first = f_t ? presum[f_t-1]+1: 1;
        return f_d<=presum[f_t]-1 && f_d>=( first%d_c? first/d_c: first/d_c-1);
    }
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int c_sz = (int)candiesCount.size();
        int q_sz = (int)queries.size();
        vector<long long> presum( c_sz );
        long long sum = 0;
        for( int i=0; i<c_sz; ++i ){
            sum += candiesCount[i];
            presum[i] = sum;
        }
        vector<bool> ans( q_sz );
        for( int i=0; i<q_sz; ++i ){
            ans[i] = judge( presum, queries[i] );
        }
        return ans;
    }
};