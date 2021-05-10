#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        my_bloom = bloomDay;
        my_m = m;
        my_k = k;
        if( m*k > bloomDay.size() ){
            return -1;
        }
        int left = 1, right = *max_element( my_bloom.begin(), my_bloom.end() );
        int mid;
        while( left+1 < right ){
            mid = ( left + right )>>1;
            if( judge( mid ) ){
                right = mid;
            }
            else{
                left = mid;
            }
        }
        return judge(left)? left: right;
    }
private:
    vector<int> my_bloom;
    int my_m, my_k;
    inline bool judge( int days ){
        int cnt=0, res=0;
        for( auto i: my_bloom ){
            if( days >= i ){
                ++cnt;
            }
            else{
                cnt = 0;
            }
            if( cnt == my_k ){
                cnt = 0;
                ++res;
            }
        }
        return res >= my_m;
    }
};