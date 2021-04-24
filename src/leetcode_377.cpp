#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        size_t sz = nums.size();
        vector< vector<unsigned int> > dp( target+1, vector<unsigned int>(sz,0) ) ;
        vector<int> temp( nums.begin(), nums.end() );
        sort( temp.begin(), temp.end() );
        for( size_t i=0; i<sz && temp[i]<=target; ++i ){
            dp[temp[i]][i] = 1;
        }
        for( size_t i=1; i<=target; ++i ){
            for( size_t j=0; j<sz && temp[j]<=i; ++j ){
                int left_target = i-temp[j];
                for( size_t k=0; k<sz && temp[k]<= left_target; ++k ){
                    dp[i][j] += dp[left_target][k];
                }
            }
        }
        unsigned int res = 0;
        for( auto &i: dp[target] ){
            res += i;
        }
        return res;
    }
};
int main(){
    srand( time(NULL) );
    printf("[");
    for( int i=0; i<200; ++i ){
        printf("%d", i+1 );
        if( i != 199 ){
            printf(",");
        }
    }
    printf("]\n");
    printf("%d\n", random()%(1000+1) );
    return 0;
}