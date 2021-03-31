#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        auto vec = nums;
        int size = nums.size();
        sort( vec.begin(), vec.end() );
        unordered_map<int, int> cnt;
        for( int i=0; i<size; ++i ){
            auto temp = cnt.emplace( vec[i], 0 );
            ++(temp.first->second);
        }
        int num = 1;
        for( auto &i : cnt ){
            num *= (i.second+1);
        } 
        auto it = unique( vec.begin(), vec.end() );
        size = it- vec.begin();
        vector< vector<int> > res;
        unordered_multiset<int> st;
        dfs(0, size, st, res, vec, cnt );
        return res;
    }
    void dfs( int index, int size, unordered_multiset<int>& st, vector< vector<int> > &res, vector<int> &vec, unordered_map<int, int>& cnt ){
        if( index==size ){
            res.emplace_back( st.begin(), st.end() );
            return;
        }
        int num = vec[index];
        int times = cnt[num];
        dfs( index+1, size, st, res, vec, cnt );
        for( int i=0; i<times; ++i ){
            st.emplace( num );
            dfs( index+1, size, st, res, vec, cnt );
        }
        st.erase( num );
        return;
    }
};
int main(){
    Solution sl;
    vector<int> vec = {1,2,2};
    sl.subsetsWithDup( vec ); 
    vec = {3,1,2,4,2,2,2,2};
    sl.subsetsWithDup( vec );
    vec = {1,2};
    sl.subsetsWithDup( vec );
    return 0;
}