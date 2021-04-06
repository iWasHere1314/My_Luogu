#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sz = nums.size();
        int pre = nums[0];
        int has_same = false;
        int res = sz;
        for( int i=1, j=-1; i<sz; ++i ){
            if( nums[i] == pre && has_same ){
                pre = nums[i];
                --res;
                if( j == -1 ){
                    j = i;
                }
            }
            else{
                has_same = nums[i] == pre;
                pre = nums[i];
                if( j != -1 ){
                    swap( nums[i], nums[j] );
                    ++j;
                }
            }
        }
        return res;
    }
};
int main(){
    Solution sl;
    vector<int> vec;
    vec = {1,1,1,2,2,3};
    sl.removeDuplicates( vec );
    vec = {0,0,1,1,1,1,2,3,3};
    sl.removeDuplicates( vec );
    vec = {1,1,1,2,2,2,3,3};
    sl.removeDuplicates( vec );
    return 0;
}