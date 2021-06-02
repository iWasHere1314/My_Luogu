#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sz = (int)nums.size();
        vector< pair<unsigned long long, int> > pre_sum( sz );
        unsigned long long sum = 0;
        unsigned long long my_k = k;
        for( int i=0; i<sz; ++i ){
            sum += (unsigned long long)nums[i];
            pre_sum[i] = make_pair( sum%my_k, i );
            if( pre_sum[i].first==0 && i!=0 ){
                return true;
            }
        }
        auto cmp = []( const pair<unsigned long long,int> &a, const pair<unsigned long long,int> &b )->bool{
            return a.first == b.first? a.second<b.second: a.first<b.first;
        };
        sort( pre_sum.begin(), pre_sum.end(), cmp );
        for( int i=1, j = 0; i<sz; ){
            auto p1 = pre_sum[i];
            auto p2 = pre_sum[j];
            if( p1.first == p2.first ){
                while( i<sz && pre_sum[i].first == p2.first ){
                    ++i;
                } 
                --i;
                p1 = pre_sum[i];
                if( p1.second - p2.second >= 2 ){
                    return true;
                }
                j = i+1;
                i += 2;
            }
            else{
                j = i;
                ++i;
            }
        }
        return false;
    }
};

int main(){
    srand( time(NULL) );
    printf("[");
    for( int i=0; i<100000; ++i ){
        printf("%d", rand()%(int)(1E4+1));
        if( i!= 99999 ){
            printf(", ");
        }
    }
    printf("]\n");
    printf("%d\n",rand()%(1<<30));
}