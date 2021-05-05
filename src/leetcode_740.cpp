//#define MY_DEBUG
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        size_t sz = nums.size();
        vector<int> vec(nums);
        vector<int>dp(2);
        sort(vec.begin(), vec.end() );
        #ifdef MY_DEBUG
        for( size_t i=0; i<sz; ++i ){
            printf( "%d ", vec[i] );
        }
        printf("\n");
        #endif
        dp[0] = 0;
        dp[1] = vec[0];
        #ifdef MY_DEBUG
            printf("loc=%d, num=%d, use=%d, not_use=%d\n",0, vec[0], dp[1], dp[0] );
            #endif
        for( size_t i=1; i<sz; ++i ){
            int res1,res0;
            if( vec[i]==vec[i-1]+1 ){
                res1 = dp[0]+vec[i];
                res0 = max( dp[0], dp[1] );
            }
            else if( vec[i]==vec[i-1] ){
                res1 = dp[1] + vec[i];
                res0 = dp[0];
            }
            else{
                res0 = max( dp[0], dp[1] );
                res1 = res0 + vec[i];
            }
            dp[0] = res0;
            dp[1] = res1;
            #ifdef MY_DEBUG
            printf("loc=%d, num=%d, use=%d, not_use=%d\n",i, vec[i], dp[1], dp[0] );
            #endif
        }
        return max(dp[0], dp[1] );
    }
};
int main(){
    srand(time(NULL) );
    printf("[");
    size_t sz = 2e4;
    for( size_t i=0; i<sz; ++i ){
        printf("%d", random()%(int)1e4 + 1 );
        if( i!=sz-1){
            printf(", ");
        }
    }
    printf("]\n");
    // vector<int> vec;
    // vec={1,2,3,4,4,4,4,4,4,4,4,4,5,6,7,8,9,9};
    // Solution sl;
    // sl.deleteAndEarn(vec);   
    return 0;
}