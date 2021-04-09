#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isUgly(int n) {
        if( !n ){
            return false;
        }
        while( !(n&1) ){
            n >>= 1;
        }
        while( !(n%3) ){
            n /= 3;
        }
        while( !(n%5) ){
            n /= 5;
        }
        return n == 1;
    }
};