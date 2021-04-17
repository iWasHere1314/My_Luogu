#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1, j=-1, sz=nums.size(), res = sz;
        int pre;
        int cur;
        if( sz>0 ){
            pre = nums[0];
        }
        while( i<sz ){
            cur = nums[i];
            if( cur == pre ){
                --res;
                if( -1 == j ){
                    j=i;
                }
            }
            else if( -1 != j ) {
                swap( nums[i], nums[j] );
                ++j;
            }
            ++i;
            pre = cur;
        }
        return res;
    }
};