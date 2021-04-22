#include<bits/stdc++.h>
using namespace std;
/* 官方的思路真是厉害 */
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int target ) {
        int line = matrix.size(), column = matrix[0].size() ;
        vector< vector< vector<int> > > dp( line, vector< vector<int> > ( column, vector<int>( column+1, 0) ) );
        vector< vector< vector<int> > > oneline( line, vector< vector<int> > ( column, vector<int>( column+1, 0 ) ) );
        int res = -1E6;
        for( int i=0; i<line; ++i ){
            for( int j=0; j<column; ++j ){
                int temp;
                for( int k=1; (temp = j+k-1) < column; ++k ){
                    oneline[i][j][k] = oneline[i][j][k-1] + matrix[i][temp];
                }
            }
        }
        for( int xlen=1; xlen<= line; ++xlen ){
            for( int i=0; i+xlen<= line; ++i ){
                for( int j=0; j<column; ++j ){
                    int e = column + 1 - j;
                    for( int k=1; k<e /*j+k-1< column */; ++k ){
                        int ans = dp[i][j][k] = dp[i][j][k] + oneline[i+xlen-1][j][k];
                        if( ans <= target && ans > res ){
                            res = ans;
                            if( res== target ){
                                return target;
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};
int main(){
    Solution sl;
    vector< vector<int> > vec;
    vec = {{5,-4,-3,4},{-3,-4,4,5},{5,1,5,-4}};
    printf("%d\n", sl.maxSumSubmatrix( vec, -2 ) );    
    vec = {{1,0,1},{0,-2,3}};
    printf("%d\n", sl.maxSumSubmatrix( vec, 2) );
    vec = {{2,2,-1}};
    printf("%d\n", sl.maxSumSubmatrix( vec, 3) );    
    return 0;
    // srand( time(NULL) );
    // printf("[");
    // for( int i=0; i<100; ++i ){
    //     printf("[");
    //     for( int j=0; j<100; ++j ){
    //         printf("%d", random()%100 );
    //         if( j != 99 ){
    //             printf(",");
    //         }
    //     }
    //     printf("]");
    //     if( i!=99 ){
    //         printf(",");
    //     }
    // }
    // printf("]\n");
    // printf("%d\n", random()%(int)1E5);
}