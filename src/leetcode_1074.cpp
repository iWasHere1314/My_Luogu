#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int sz1 = (int)matrix.size(), sz2 = (int)matrix[0].size();
        vector< vector<int> > pre_sum( sz1, vector<int>( sz2, 0) );
        int res = 0;
        for( int i=0; i<sz1; ++i ){
            for( int j=0; j<sz2; ++j ){
                int pre_i = i-1;
                int pre_j = j-1;
                int sum = matrix[i][j];
                bool f_i =  pre_i >= 0;
                bool f_j = pre_j >=0;
                if( f_i ){
                    sum += pre_sum[pre_i][j];
                }
                if( f_j ){
                    sum += pre_sum[i][pre_j];
                }
                if( f_i && f_j ){
                    sum -= pre_sum[pre_i][pre_j];
                }
                pre_sum[i][j] = sum;
            }
        }
        for( int i=0; i<sz1; ++i ){
            for( int j=i; j<sz1; ++j ){
                unordered_map<int, int> mp;
                for( int k=0; k<sz2; ++k ){
                    int sum = pre_sum[j][k];
                    if( i>0 ){
                        sum -= pre_sum[i-1][k];
                    }
                    if( sum == target ){
                        ++ res;
                    }
                    auto t1 = mp.find( sum-target );
                    if( t1 != mp.end() ){
                        res += t1->second;
                    }
                    auto t2 = mp.emplace( sum, 0 );
                    ++( t2.first->second );
                }
            }
        }
        return res;
    }
};