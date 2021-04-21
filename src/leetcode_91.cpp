#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    Solution(){
        for( int i=1; i<=26; ++i ){
            mp.insert( to_string(i) );
        }
    }
    int numDecodings(string s) {
        int sz = s.size();
        int pre1=0, pre2=0, cur=1;
        if( '0' == s[0] ){
            return 0;
        }
        else{
            pre1 = 1;
            if( sz>1 ){
                pre2 = pre1;
                pre1 = 0;
                if( s[1] != '0' ){
                    ++pre1;
                }
                if( mp.find( s.substr( 0, 2 ) ) != mp.end() ){
                    ++pre1;
                }
                for( int i=2; i<sz; ++i ){
                    cur = 0;
                    if( pre1 != 0 && s[i] != '0' ){
                        cur += pre1;
                    }
                    if( pre2 != 0 && mp.find( s.substr( i-1, 2 ) ) != mp.end() ){
                        cur += pre2;
                    }
                    if( 0==cur && 0==pre1 ){
                        return 0;
                    }
                    pre2 = pre1;
                    pre1 = cur;
                }
            }
        }
        return pre1;
    }
private:
    set<string> mp;
};
int main(){
    Solution sl;
    printf("%d\n", sl.numDecodings( "12" ) );
    printf("%d\n", sl.numDecodings( "226" ) );
    printf("%d\n", sl.numDecodings( "0" ) );
    printf("%d\n", sl.numDecodings( "06" ) );
    printf("%d\n", sl.numDecodings( "000" ) );
    printf("%d\n", sl.numDecodings( "00" ) );
    printf("%d\n", sl.numDecodings( "00123456" ) );
    printf("%d\n", sl.numDecodings( "123456" ) );
    printf("%d\n", sl.numDecodings( "1" ) );
    printf("%d\n", sl.numDecodings( "62" ) );
    // srand( time(NULL) );
    // for( int i=0; i<5; ++i ){
    //     for( int i=0; i<100; ++i ){
    //         printf("%d", random()%10 );
    //     }
    //     printf("\n");
    // }
    return 0;
}