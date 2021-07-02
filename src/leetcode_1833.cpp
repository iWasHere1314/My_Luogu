#include<bits/stdc++.h>
using namespace std;
/* class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins){
        int sz = (int)costs.size();
        vector<int> dp( coins+1 );
        for( int j=costs[0]; j<=coins; ++j ){
            dp[j] = 1;
        }
        for( int i=1; i<sz; ++i ){
            int jmin = costs[i];
            for( int j=coins; j>=jmin; --j ){
                dp[j] = max( dp[j], dp[j-jmin]+1 );
            }
        }
        return dp[coins];
    }
}; */
/* 背包一般不只是加一..... */
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int count = 0;
        int n = costs.size();
        for (int i = 0; i < n; i++) {
            int cost = costs[i];
            if (coins >= cost) {
                coins -= cost;
                count++;
            } else {
                break;
            }
        }
        return count;
    }
};