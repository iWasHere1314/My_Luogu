#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r = nums.size()-1, mid = (l+r)/2;
        while( l<r-1 ){
            if( nums[l] == nums[r] && nums[l] == nums[mid] ){
                l++;
            }
            else if( nums[mid] >= nums[l] ){
                if( nums[l] >= nums[r] ){
                    l = mid;
                }
                else{
                    r = mid;
                }
            }
            else{
                r = mid;
            }
            mid = (l+r)/2;
        }
        return min( nums[l], nums[r] );
    }
};