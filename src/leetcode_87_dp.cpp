#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int sz = s1.size();    
        for( int i=0; i<sz; ++i ){
            for( int j=0; j<sz; ++j ){
                dp[i][i+1][j][j+1] = (s1[i]==s2[j]);
                //printf("\tlen=%d %d %d %d %d %s\n",1, i, i+1-1, j, j+1-1, dp[i][i+1][j][j+1]? "yes": "no" );
            }
        }
        for( int len=2; len<=sz; ++len ){
            int sz1 = sz-len;
            for( int i=0; i<=sz1; ++i ){
                for( int j=0; j<=sz1; ++j ){
                    bool res=false;
                    for( int l=1; l<=len; ++l ){
                        int a_b=i, a_e=i+len, b_b=j, b_e=j+len, a_bm=a_b+l, b_bm=b_b+l,
                            b_em = b_e-l;
                        res |= ( dp[a_b][a_bm][b_b][b_bm] & dp[a_bm][a_e][b_bm][b_e] ) |
                                ( dp[a_b][a_bm][b_em][b_e] & dp[a_bm][a_e][b_b][b_em] );
                        if( res ){
                            break;
                        } 
                    }
                    dp[i][i+len][j][j+len] = res;
                    //printf("\tlen=%d %d %d %d %d %s\n",len, i, i+len-1, j, j+len-1, dp[i][i+len][j][j+len]? "yes": "no" );
                }
            }
        }
        return dp[0][sz][0][sz];
    }
private:
    static const int MAX_L = 30+1;
    bool dp[MAX_L][MAX_L][MAX_L][MAX_L];
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