#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int sz1 = s1.size(), sz2 = s2.size();
        str1 = s1;
        str2 = s2;    
        return judge( 0, sz1, 0, sz2 ); 
    }
private:
    string str1, str2;
    bool judge( int a_b, int a_e, int b_b, int b_e ){
        if( a_b+1 == a_e ){
            return str1[a_b]==str2[b_b];
        }
        int res=false;
        int len = a_e - a_b;
        for( int i=1; i<len; ++i ){
            int a_bm = a_b+i, b_bm = b_b+i, b_em = b_e-i;
            res |= ( judge(a_b, a_bm, b_b, b_bm ) && judge(a_bm, a_e, b_bm, b_e ) ) ||
                       ( judge(a_b, a_bm, b_em, b_e) && judge( a_bm, a_e, b_b, b_em ) );
            if( res ){
                break;
            }    
        }
        return res ;
    }
};
int main(){
    Solution sl;
    printf("%d\n", sl.isScramble("ab","ba" ) );
    printf("%d\n", sl.isScramble("great","rgeat" ) );
    printf("%d\n", sl.isScramble("abcde","caebd" ) );
    printf("%d\n", sl.isScramble("a","a" ) );
    printf("%d\n", sl.isScramble("abcde","ecdba" ) );
    printf("%d\n", sl.isScramble("ab","cd" ) );
    printf("%d\n", sl.isScramble("ccabcbabcbabbbbcbb", "bbbbabccccbbbabcba" ) );
    return 0;
}