#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sz = (int)nums.size();
        vector< pair<int, int> > pre_sum( sz );
        int sum = 0;
        int res = 0;
        for( int i=0; i<sz; ++i ){
            sum += nums[i];
            if( 2*sum == (i+1) ){
                res = i+1;
            }
            pre_sum[i].first = 2*sum-(i+1);
            pre_sum[i].second = i;
        }
        auto cmp = []( const pair<int,int> &a, const pair<int, int> &b)->bool{
            return a.first == b.first? a.second<b.second: a.first<b.first;
        };
        sort( pre_sum.begin(), pre_sum.end(), cmp );
        for( int i=1, j=0; i<sz; ){
            auto pre = pre_sum[j];
            auto cur = pre_sum[i];
            if( pre.first == cur.first ){
                while( i<sz && pre.first == pre_sum[i].first ){
                    ++i;
                }
                --i;
                int t = pre_sum[i].second - pre.second;
                if( t>res ){
                    res = t;
                }
                j = i+1;
                i += 2;
            }   
            else{
                j = i;
                ++i;
            } 
        }
        return res;
    }
};

int main(){
    srand(time(NULL));
    printf("[");
    for( int i=0; i<(int)1E5; ++i ){
        printf("%d",rand()%2);
        if( i!= (int)1E5-1 ){
            printf(",");
        }
    }
    printf("]\n");
    return 0;
}