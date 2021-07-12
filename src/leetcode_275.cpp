#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int sz = (int)citations.size();
        int l = 0, r = citations[sz-1];
        int m;
        while( l+1 < r ){
            m = (l+r) >> 1;
            if( judge(m, citations ) ){
                l = m;
            }
            else{
                r = m;
            }
        }
        return judge(r,citations)? r: l;
    }
    inline bool judge( int res, vector<int>& citations ){
        auto it = lower_bound(citations.begin(), citations.end(), res );
        if( citations.end()- it >= res ){
            return true;
        }
        return false;
    }
};