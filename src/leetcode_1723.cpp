#define MY

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        size_t sz = jobs.size();
        size_t my_k = k;
        size_t cnt_sz = 1<<(sz);
        vector< vector<int> > dp( my_k, vector<int>(cnt_sz, 0x7fffffff ) );
        vector< int > sum( cnt_sz, 0  );
        
        for( size_t i=0; i<cnt_sz; ++i ){
            for( size_t j=0; j<sz; ++j ){
                if( i&(1<<j) ){
                    sum[i] += jobs[j];
                }
            }
        }
        for( size_t i=0; i<cnt_sz; ++i ){
            dp[0][i] = sum[i];
        }
        for( size_t i=1; i<my_k; ++i ){
            for( size_t j=0; j<cnt_sz; ++j ){
                int res = dp[i][j];
                for( size_t l=j; l; l = (l-1)&j ){//也会有重复， 但这样的计算代价最小
                    res = min( res, max( dp[i-1][l], sum[j-l] ) );
                }
                dp[i][j] = res;
            }
        }
        return dp[my_k-1][cnt_sz-1];
    }
};
#ifdef MY
int main(){
    Solution sl;
    vector<int> vec;
    vec = {3,2,3};
    printf( "%d\n\n\n", sl.minimumTimeRequired(vec,3) );
    vec = {1,2,4,7,8 };
    printf( "%d\n", sl.minimumTimeRequired(vec, 2 ) );
}
#endif 