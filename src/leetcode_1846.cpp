#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort( arr.begin(), arr.end() );
        int sz = (int)arr.size();
        arr[0] = 1;
        int pre = 1;
        for( int i=1 ; i<sz; ++i ){
            if( arr[i] - pre > 1 ){
                arr[i] = pre + 1;
            }
            pre = arr[i];
        }
        return *( arr.end()-1 );
    }
};