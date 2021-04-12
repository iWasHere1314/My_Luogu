#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int sz = nums.size();
        vector<string> strs( sz );
        for( int i=0; i<sz; ++i ){
            strs[i] = to_string( nums[i] );
        }
        auto greater = []( const string& a, const string& b )->bool{
            int i,j;
            i = j = 0;
            int sz1=a.size(), sz2=b.size();
            while( i<sz1 && j<sz2 ){
                if( a[i]!=b[j] ){
                    return a[i]>b[j];
                }
                ++i;
                ++j;
            }
            if( i==sz1 ){
                while( j<sz2 ){
                    i = i%sz1;
                    if( a[i]!=b[j] ){
                        return a[i]>b[j];
                    }
                    ++i;
                    ++j;   
                }
            }
            if( j==sz2 ){
                char c = a[sz2-1];
                while( i<sz1 ){
                    j = j%sz2;
                    if( a[i]!=b[j] ){
                        return a[i]>b[j];
                    }
                    ++i;
                    ++j;
                }
            }
            if( sz1>sz2 ){
                i = sz1-sz2;
                j = 0;
            }
            else{
                i = 0;
                j = sz2-sz1;
            }
            while( i<sz1 ){
                if( a[i]!=b[j] ){
                    return a[i]<b[j];
                }
                ++i;
                ++j;
            }
            return false;
        };
        sort( strs.begin(), strs.end(), greater );
        string res;
        for( auto &i: strs ){
            res += i;
        }
        return res[0] == '0'? "0": res;
    }
};
int main(){
    vector<int> vec = {00,000,0000};
    Solution sl;
    auto i = sl.largestNumber( vec );
    i;
    return 0;
}