#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n>0 && (n&(-n)&0b1010101010101010101010101010101)==n ;
    }
};