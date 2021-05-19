#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        size_t sz = arr.size();
        vector<int> pre(sz);
        int sum = 0;
        for( size_t i=0; i<sz; ++i ){
            sum ^= arr[i];
            pre[i] = sum;
        }
        int res = 0;
        for( size_t i=0; i<sz-1; ++i ){
            for( size_t j=i+1; j<sz; ++j ){
                int temp = pre[j];
                if( i ){
                    temp ^= pre[i-1];
                }
                if( !temp ){
                    res += j-i;
                }
            }
        }
        return res;
    }
};