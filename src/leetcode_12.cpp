#define MY

#ifdef MY
    #include<bits/stdc++.h>
    using namespace std;
#endif

class Solution {
public:
    string intToRoman(int num) {
        vector<int> nums
            { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        vector<string> 
            strs{ "M","CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
        string res;
        size_t sz = nums.size();
        for( size_t i=0; i<sz && num; ++i ){
            int n = nums[i];
            string str = strs[i];
            int times = num / n;
            if( times ){
                num %= n;
                res.reserve( res.length()+times*str.length() );
                size_t sz1 = str.size();
                for( int j=0; j<times; ++j ){
                    res.insert( res.length(), str );
                }
            }
        }
        return res;
    }
};

#ifdef MY
    int main(){
        Solution sl;
        sl.intToRoman( 3 );
        sl.intToRoman( 4 );
        sl.intToRoman( 58 );
        sl.intToRoman( 2990 );

    }
#endif