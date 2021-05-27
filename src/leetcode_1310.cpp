#define MY

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        size_t arr_sz = arr.size(), q_sz = queries.size();
        vector<int> prefix( arr_sz );
        vector<int> res( q_sz );
        int sum=0;
        for( size_t i=0; i<arr_sz; ++i  ){
            sum ^= arr[i];
            prefix[i] = sum;
        }
        for( size_t i=0; i<q_sz; ++i ){
            auto &t = queries[i];
            auto l = t[0], r = t[1];
            sum = 0;
            if( l>0 ){
                sum = prefix[l-1];
            }
            sum ^= prefix[r];
            res[i] = sum;
        }
        return res;
    }
};