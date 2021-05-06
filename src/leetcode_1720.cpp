#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        size_t sz = encoded.size() + 1;
        vector<int> origion( sz );
        origion[0] = first;
        for( size_t i=1; i<sz; ++i ){
            size_t loc = i-1;
            origion[i] = encoded[loc] ^ origion[loc];
        }
        return origion;
    }
};