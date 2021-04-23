#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> temp(nums);
        sort( temp.begin(), temp.end() );
        size_t sz = temp.size();
        vector<int> dp( sz, 0 );
        vector<size_t> par( sz );
        size_t loc=0;
        for( size_t i=0; i<sz; ++i ){
            par[i] = i;
        }
        for( size_t i=0; i<sz; ++i ){
            for( size_t j=0; j<i; ++j ){
                if( 0 == temp[i]%temp[j] ){
                    if( dp[j]>dp[i] ){
                        dp[i] = dp[j];
                        par[i] = j;
                    }
                }
            }
            ++dp[i];
            if( dp[i] > dp[loc] ){
                loc = i;
            }
        }
        deque<int> res;
        while( par[loc] != loc ){
            res.push_front( temp[loc] );
            loc = par[loc];
        }
        res.push_front( temp[loc] );
        return vector<int>( res.begin(), res.end() );
    }
};
int main(){
    srand( time(NULL) );
    printf("[");
    for( size_t i=0; i<1000; ++i ){
        printf("%d", (int)i+1 );
        if( i!=999 ){
            printf(",");
        }
    }
    printf("]\n");
    return 0;
}