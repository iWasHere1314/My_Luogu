#define MY_DEBUG

#include<bits/stdc++.h>
using namespace std;
const int MOD = 1E9 + 7;
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int sz = (int)nums1.size();
        vector<int> res(sz);
        for( int i=0; i<sz; ++i ){
            res[i] = abs( nums1[i] - nums2[i] );
        }
        auto temp = nums1;
        sort( temp.begin(), temp.end() );
        int mx = 0;
        int index = -1;
        #ifdef MY_DEBUG
            int org;
            int now;
        #endif
        for( int i=0; i<sz; ++i ){
            int val = nums2[i];
            auto it = lower_bound( temp.begin(), temp.end(), val );
            int rdc = -1E6;
            if( it != temp.begin() ){
                int cur_diff = abs( *(it-1) - val );
                rdc = res[i] - cur_diff;
                #ifdef MY_DEBUG
                    if( rdc > mx ){
                        org = val;
                        now = *(it-1); 
                    }
                #endif
            }
            if( it != temp.end() ){
                rdc = max( rdc, res[i]-abs( *(it) - val ) );
                #ifdef MY_DEBUG
                    if( rdc > mx && ( it==temp.begin() || ( it!=temp.begin() && rdc > res[i]-abs( *(it-1) - val ) ) ) ){
                        org = val;
                        now = *(it); 
                    }
                #endif
            }
            if( rdc > mx ){
                mx = rdc;
                index = i;
            }
        }
        if( index != -1 ){
            res[index] -= mx;
        }
        int ret = 0;
        for( int i=0; i<sz; ++i ){
            ret += res[i];
            ret %= MOD;
        }
        #ifdef MY_DEBUG
            printf("%d, %d, %d\n", org, now, mx );
        #endif
        return (int)ret;
    }
};
int main(){
    vector<int> vec1={1,10,4,4,2,7}, vec2={9,3,5,1,7,4};
    Solution sl;
    sl.minAbsoluteSumDiff( vec1, vec2 );
    return 0;
}