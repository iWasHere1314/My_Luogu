#define MY_DEBUG
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        const int INF = 0x7fffffff;
        vector< vector <int> > dp( n, vector<int>(target+1, INF) );
        vector< vector <int> > dp_pre( n, vector<int>(target+1, INF) );
        if( houses[0] ){
            dp_pre[houses[0]-1][1] = 0;
            #ifdef MY_DEBUG
            printf( "loc=%d, color=%d, target=%d, min_cost=%d\n", 0, houses[0], 1, dp_pre[houses[0]][1] );   
            #endif
        }
        else{
            for( int j=0; j<n; ++j ){
                dp_pre[j][1] = cost[0][j];
                #ifdef MY_DEBUG
                printf( "loc=%d, color=%d, target=%d, min_cost=%d\n",0 ,j+1, 1, dp_pre[j][1] );
                #endif
            }
        }
        for( int i=1; i<m; ++i ){
            if( houses[i] ){
                int loc = houses[i]-1;
                for( int k=target; k>=1; --k ){
                    int res = dp_pre[loc][k];
                    for( int l=0; l<n; ++l ){
                        if( l != loc ){
                            res = min( res, dp_pre[l][k-1] );
                        }
                    }
                    dp[loc][k] = res;
                    #ifdef MY_DEBUG
                    printf( "loc=%d, color=%d, target=%d, min_cost=%d\n",i, loc+1, k, dp_pre[loc][k] );
                    #endif
                }
                for( int j=0; j<n ; ++j ){
                    if( j != loc ){
                        fill( dp[j].begin(), dp[j].end(), INF );
                    }
                }
            }   
            else{
                for( int j=0; j<n; ++j ){
                    for( int k=target; k>=1; --k ){
                        int res = dp_pre[j][k];
                        for( int l=0; l<n; ++l ){
                            if( l != j ){
                                res = min( res, dp_pre[l][k-1] );
                            }
                        }
                        if( res != INF ){
                            res += cost[i][j];
                        }
                        dp[j][k] = res;
                        #ifdef MY_DEBUG
                        printf( "loc=%d, color=%d, target=%d, min_cost=%d\n", i, j+1, k, dp_pre[j][k] );
                        #endif
                    }
                }
            } 
            dp_pre.swap(dp);        
        }
        int res=INF;
        for( int j=0; j<n; ++j ){
            res = min( res, dp_pre[j][target] );
        }
        return res == INF? -1: res;
    }
};
int main(){
    Solution sl;
    vector<int> vec = {0,0,0,0,0};
    vector< vector<int> > vec_vec = {{1,10},{10,1},{10,1},{1,10},{5,1}};
    printf("%d\n",sl.minCost( vec, vec_vec, 5, 2, 3 ));
}