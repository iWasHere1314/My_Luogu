#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int sz1 = haystack.size(), sz2 = needle.size();
        vector<int> next( sz2 );
        if( sz2>0 ){
            next[0] = -1;
        }
        if( sz2>1 ){
            next[1] = 0;
        }
        int j=0, i=1;
        int t_sz = sz2-1;
        while( i<t_sz ){
            if( -1 == j ){
                next[++i] = j = 0;
            }
            else if( needle[i] == needle[j] ){
                next[++i] = ++j;
            }
            else{
                j = next[j];
            } 
        }
        i=0;
        j=0;
        while( i<sz1 && j<sz2 ){
            if( -1 == j ){
                j = 0;
                ++i;
            }
            else if( haystack[i] == needle[j] ){
                ++i;
                ++j;
            }
            else{
                j = next[j];
            }
        }
        return j==sz2? i-j: -1; 
    }
};
int main(){
    Solution sl;
    printf("%d\n",sl.strStr( "hello", "ll") );
    printf("%d\n",sl.strStr( "aaaaa", "bba"));
    printf("%d\n",sl.strStr( "", ""));
    printf("%d\n",sl.strStr( "aaaa", "aa"));
    printf("%d\n",sl.strStr( "aaaa", "" ));
    printf("%d\n",sl.strStr( "aabcaabcd", "abcd" ));
    printf("%d\n",sl.strStr( "dabaabc", "abaabc" ));
    printf("%d\n",sl.strStr( "abaabcd", "abaabc" ));
    printf("%d\n",sl.strStr( "dabaabcd", "abaabc" ));
    return 0;
}