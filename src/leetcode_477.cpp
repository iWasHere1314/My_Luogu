#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res=0;
        int cnt = (int)nums.size();
        for( int i=0; i<31; ++i ){
            int zc = 0;
            for( int j=0; j<cnt; ++j ){
                if( ! (nums[j] & (1<<i)) ){
                    ++zc;
                }
            }
            res += zc * ( cnt -zc );
        }
        return res;
    }
};