#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        size_t sz1 = nums1.size(), sz2 = nums2.size();
        vector< vector<int> > dp( sz1, vector<int>( sz2, 1 ) );
        for( size_t j=0; j<sz2; ++j ){
            if( nums1[0] != nums2[j] ){
                dp[0][j] = 0;
            }
            else{
                break;
            }
        }
        for( size_t i=1; i<sz1; ++i ){
            for( size_t j=0; j<sz2; ++j ){
                int temp = nums1[i] == nums2[0] ? 1: 0;
                temp = max( temp, dp[i-1][j] );
                for( size_t k=1; k<=j; ++k ){
                    if( nums1[i] == nums2[k] ){
                        temp = max( temp, dp[i-1][k-1]+1 );
                    }
                }
                dp[i][j] = temp;
            }
        }
        return dp[sz1-1][sz2-1];
    }
};