#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool judgeSquareSum(int c) {
        long long a=0, b=my_sqrt(c);
        while( a<b ){
            long long temp = a*a + b*b;
            if( temp > c ){
                --b;
            }
            else if( temp <c ){
                --a;
            }
            else{
                return true;
            }
        }
        return a*a == c;
    }
private:
    long long my_sqrt( int num ){
        long long l=0, r=num, mid;
        while( l+1 < r ){
            mid = ( l + r )>>1;
            long long temp = mid * mid;
            if( temp >= num ){
                r = mid;
            }
            else if( temp < num ){
                l = mid;
            }
        }
        return r;
    }
};