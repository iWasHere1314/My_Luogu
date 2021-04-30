#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for( int i=0; i<32; ++i ){
            int temp=0;
            for( auto &j: nums ){
                temp += ( j>>i)&1;
            }
            temp %= 3;
            ans += temp<<i;
        }
        return ans;
    }
};