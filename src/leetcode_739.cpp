#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> stk;
        stk.push(0);
        int sz = T.size();
        vector<int> res(sz,0);
        for( int i=1; i<sz; ++i ){
            int j = stk.top();
            if( T[i]<=T[j] ){
                stk.push( i );
            }
            else{
                while( stk.size() && T[i]>T[j=stk.top()] ){
                    stk.pop();
                    res[j] = i-j;
                }
                stk.push(i);
            }
        }
        return res;
    }
};
int main(){
    Solution sl;
    vector<int> vec{34,80,80,34,34,80,80,80,80,34};
    auto res = sl.dailyTemperatures( vec );
    for( int i=0; i<res.size(); ++i ){
        printf("%d ", res[i] );
    }
    printf("\n");
    return 0;
}