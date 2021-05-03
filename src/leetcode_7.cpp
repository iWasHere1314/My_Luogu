#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int res=0;
        int t_x = abs(x);
        while( t_x ){
            if( res > INT32_MAX/10 || res<INT32_MIN/10 ){
                return 0;
            }
            res *= 10;
            res += t_x%10;
            t_x /= 10;
        }
        return x>0 ? res: -res;
    }
};