#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, long long k, long long t) {
        unordered_map<long long, long long> mp;
        long long sz = nums.size();
        for( long long i=0; i<sz; ++i ){
            long long loc = (nums[i]+2E4)/(t+1);
            decltype( mp.end() ) it;
            if( ( it=mp.find(loc) ) != mp.end() ){
                if( abs(it->second - i ) <= k ){
                    return true;
                }
                else{
                    it->second = i;
                }
            }
            mp[loc] = i;
            if( ( it = mp.find(loc-1) ) != mp.end() ){
                if( abs((long long)nums[it->second] - (long long)nums[i] ) <= t && abs(it->second - i ) <= k ){
                    return true;
                }
            }
            if( ( it = mp.find(loc+1) ) != mp.end() ){
                if( abs((long long)nums[it->second] - (long long)nums[i] ) <= t && abs(it->second - i ) <= k ){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    Solution sl;
    vector<int> vec;
    vec = {2147483647,-1,2147483647};
    sl.containsNearbyAlmostDuplicate( vec, 1, 2147483647);
}