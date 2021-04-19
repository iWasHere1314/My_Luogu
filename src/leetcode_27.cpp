#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = -1, sz = nums.size(), ret = sz;;
        while( i<sz ){
            if( nums[i] == val ){
                if( -1 == j ){
                    j = i;
                }
                --ret;
            }
            else if( -1 != j ){
                swap( nums[i], nums[j] );    
                ++j;
            }
            ++i;
        }
        return ret;
    }
};