#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto sz = matrix.size();
        vector<int> vec( sz );
        for( int i=0; i<sz; ++i ){
            vec[i] = matrix[i][0];
        }
        auto it = lower_bound( vec.begin(),  vec.end(), target );
        int i;
        if( it != vec.end() ){
            i = *it;
            if( i==target ){
                return true;
            }
        }    
        if( it == vec.begin() ){
            return false;
        }
        i = it-vec.begin()-1;
        it = lower_bound( matrix[i].begin(), matrix[i].end(), target );
        return it != matrix[i].end() && *it==target;
    }
};

int main(){
    Solution sl;
    vector<vector<int> > martix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    printf("%d\n", sl.searchMatrix(martix, 3 ) );
    printf("%d\n", sl.searchMatrix(martix, 13 ) );

    return 0;
}