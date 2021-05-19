#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        size_t sz1 = matrix.size(), sz2 = matrix[0].size();
        vector<int> res( sz1*sz2 );
        size_t cnt = 0;
        vector< vector< int > > pre_sum( sz1, vector<int>(sz2, 0) );
        for( size_t i=0; i<sz1; ++i ){
            for( size_t j=0; j<sz2; ++j ){
                int temp = matrix[i][j];
                size_t pre_i = i-1;
                size_t pre_j = j-1;
                bool flag_i = i >= 1;
                bool flag_j = j >= 1;
                if( flag_i ){
                    temp ^= pre_sum[pre_i][j];
                }
                if( flag_j ){
                    temp ^= pre_sum[i][pre_j];
                }
                if( flag_i && flag_j ){
                    temp ^= pre_sum[pre_i][pre_j];
                }
                pre_sum[i][j] = temp;
                res[cnt++] = temp;
            }
        }
        auto it = res.begin() + k - 1;
        nth_element( res.begin(), it, res.end(), greater<int>() );
        return *it;
    }
};

int main(){
    Solution sl;
    vector< vector<int> > vec = {{8,10,5,8,5,7,6,0,1,4,10,6,4,3,6,8,7,9,4,2}};
    int pre = 0;
    for( int i=0; i<20; ++i ){
        pre ^= vec[0][i];
        printf("%d ", pre );
    }
    printf("\n");
    sl.kthLargestValue(vec, 2);
}