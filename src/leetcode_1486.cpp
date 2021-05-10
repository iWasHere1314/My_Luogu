#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int xorOperation(int n, int start) {
        int s = start+2;
        int res = start;
        for( int i=1; i<n; ++i, s+=2 ){
            res ^= s;
        }
        return res;
    }
};