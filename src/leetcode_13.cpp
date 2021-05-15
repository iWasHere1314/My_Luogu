#define MY

#ifdef MY
    #include<bits/stdc++.h>
    using namespace std;
#endif
class Solution {
public:
    int romanToInt(string s) {
        vector<int> nums
            { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        vector<string> 
            strs{ "M","CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
        int res = 0;
        size_t sz = s.length();
        for( size_t i=0, j=0; j<13 && i<sz; ++j ){
            string str = strs[j];
            int num = nums[j];
            int cnt = 0;
            size_t l = str.length();
            while( i<sz ){
                if( s.substr(i,l) == str ){
                    i += l;
                    ++cnt;
                }
                else{
                    break;
                }
            }
            res += cnt * num;
        }
        return res;
    }
};

#ifdef MY
    int main(){
        Solution sl;
        sl.romanToInt( "III" );
        sl.romanToInt( "IV" );
        sl.romanToInt( "IX" );
        sl.romanToInt( "LVIII" );
        sl.romanToInt( "MCMXCIV" );
        sl.romanToInt( "XLIX" );
        sl.romanToInt( "CMXCIX" );
    }
#endif