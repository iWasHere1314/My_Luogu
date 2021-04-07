#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1, mid = (l+r)/2;
        while( l<r-1 ){
            if( nums[mid] == target ){
                return mid;
            }
            if( nums[l] == nums[mid] && nums[r] == nums[mid] ){
                ++l;
                --r;
            }
            else if( nums[l]<=nums[mid] && nums[mid] >= nums[r] ){
                if( nums[l]<= target && nums[mid] >= target ){
                    r = mid;
                }
                else{
                    l = mid;
                }
            }
            else{
                if( nums[mid]<= target && nums[r] >= target ){
                    l = mid;
                }
                else{
                    r = mid;
                }
            }
            mid = (l+r)/2;
        }
        if( nums[l]==target ){
            return l;
        }
        if( nums[r]==target ){
            return r;
        }
        return  -1  ;
    }
};