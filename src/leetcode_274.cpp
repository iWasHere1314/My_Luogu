#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int sz = *max_element( citations.begin(), citations.end() );
        ++sz;
        vector<int> cnt( sz );
        for( auto i: citations ){
            ++cnt[i];
        }
        for( int i=sz-2; i>=0; --i ){
            cnt[i] += cnt[i+1]; 
        }
        for( int i=sz-1; i>=0; --i ){
            if( cnt[i] >= i ){
                return i;
            }
        }
        return 0;
    }
};

int main(){
    vector<int> vec= {4,5,6,7,8,9,10};
    Solution sl;
    int res = sl.hIndex( vec );
    return 0;
}