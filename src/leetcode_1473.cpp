#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        my_houses = houses;
        my_cost = cost;
        my_m = m;
        my_n = n;
        my_target = target;
        res = INT32_MAX;
        dfs( 0, 0, 0 );
        return res==INT32_MAX? -1: res ;
    } 
private:
    vector<int> my_houses;
    vector<vector<int>> my_cost;
    int my_m, my_n, my_target;
    int res;
    void dfs( int loc, int blocks_cnt, int cur_cost ){
        bool pre_existed = loc>0;
        if( loc == my_m - 1){
            if( my_houses[loc] == 0 ){
                for( int i=0; i<my_n; ++i ){
                    if( cur_cost + my_cost[loc][i] < res ){
                        if( pre_existed ){
                            if( i+1 != my_houses[loc-1] && blocks_cnt + 1 == my_target ){
                                res = cur_cost + my_cost[loc][i];
                            }
                            else if( i+1 == my_houses[loc-1] && blocks_cnt == my_target ){
                                res = cur_cost + my_cost[loc][i];
                            }
                        }
                        else{
                            if( blocks_cnt + 1 == my_target ){
                                res = cur_cost + my_cost[loc][i];
                            }
                        }
                    }
                }
            }
            else{
                if( pre_existed ){
                    if( my_houses[loc] != my_houses[loc-1] && blocks_cnt + 1 == my_target ){
                        res = cur_cost;
                    }
                    else if( my_houses[loc] == my_houses[loc-1] && blocks_cnt == my_target ){
                        res = cur_cost;
                    }
                }
                else{
                    if( blocks_cnt + 1 == my_target ){
                        res = cur_cost;
                    }
                }
            }
        }
        else{
            if( my_houses[loc] == 0 ){
                for( int i=0; i<my_n; ++i ){
                    if( cur_cost + my_cost[loc][i] < res ){
                        if( pre_existed ){
                            if( i+1 != my_houses[loc-1] && blocks_cnt + 1 <= my_target ){
                                my_houses[loc] =i+1;
                                dfs( loc+1, blocks_cnt+1, cur_cost + my_cost[loc][i] );
                                my_houses[loc] = 0;
                            }
                            else if( i+1 == my_houses[loc-1] ){
                                my_houses[loc] = i+1;
                                dfs( loc+1, blocks_cnt, cur_cost + my_cost[loc][i] );
                                my_houses[loc] = 0;
                            }
                        }
                        else{
                            if( blocks_cnt + 1 <= my_target ){
                                my_houses[loc] = i+1;
                                dfs( loc+1, blocks_cnt+1, cur_cost + my_cost[loc][i] );
                                my_houses[loc] = 0;
                            }
                        }
                    }
                }
            }
            else{
                if( pre_existed ){
                    if( my_houses[loc] != my_houses[loc-1] && blocks_cnt + 1 <= my_target ){
                        dfs( loc+1, blocks_cnt+1, cur_cost );
                    }
                    else if( my_houses[loc] == my_houses[loc-1] ){
                        dfs( loc+1, blocks_cnt, cur_cost );
                    }
                }
                else{
                    if( blocks_cnt + 1 <= my_target ){
                        dfs( loc+1, blocks_cnt+1, cur_cost );
                    }
                }
            }
        }
    }
};
int main(){
    Solution sl;
    vector<int> vec = {0,2,1,2,0};
    vector< vector<int> > vec_vec = {{1,10},{10,1},{10,1},{1,10},{5,1}};
    printf("%d\n",sl.minCost( vec, vec_vec, 5, 2, 3 ));
}