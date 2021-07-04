#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int sz = (int)nums.size();
        vector<int> used( sz+1, 0 );
        for( auto i: nums ){
            ++used[i];
        }
        vector<int> res(2);
        for( int i=1; i<=sz; ++i ){
            int temp = used[i];
            if( 0 == temp ){
                res[1] = i;
            }
            else if( 2 == temp ){
                res[0] = i;
            }
        }
        return res;
    }
};