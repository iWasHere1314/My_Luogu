#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> val_stk;
        int size = height.size();
        int res = 0;
        for( int i=0; i<size; ++i ){
            int temp;
            while( val_stk.size() && height[i]>= height[ ( temp = val_stk.top() ) ] ){
                val_stk.pop();
                if( val_stk.size() ){
                    int lb = val_stk.top();
                    res += (i-lb-1) * ( min(height[i],height[lb]) - height[temp] );
                }
            }
            val_stk.push( i );
        }
        return res;
    }
};
int main(){
    Solution sl;
    vector<int> vec;
    vec = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    printf("%d\n", sl.trap( vec ) );
    vec = { 4,2,1,0,3,4 };
    printf("%d\n", sl.trap( vec ) );
    vec = { 4,4,4,4,4,4,4 };
    printf("%d\n", sl.trap( vec ) );
    vec = { 4,3,4,3,4,3,4,3,4,5 };
    printf("%d\n", sl.trap( vec ) );
    return 0;
}