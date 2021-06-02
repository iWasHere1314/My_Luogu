#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_set<string> st={"1","2","4","8","61","32","64","821","652","521","4210","8420","9640","9821","86431","87632","66553","732110","644221","885422","8765410","9752210","9444310","8888630","77766211","55443332","88766410","877432211","866554432","987653210","8774432110"};
        if( n<=0 ){
            return false;
        }
        string a = to_string(n);
        sort( a.begin(), a.end(), greater<char>() );
        return st.find( a ) != st.end();
    }
};
// int main(){
//     for( int i=0, j=1; i<32; j<<=1, ++i ){
//         string a = to_string(j);
//         sort(a.begin(), a.end(),greater<char>() );
//         printf( "\"%s\",", a.c_str() );
//     }
//     return 0;
// }