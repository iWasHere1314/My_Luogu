#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int res=0;
        set< pair<int, int>, decltype(cmp)*> st(cmp);
        map<int,int> mp;
        auto size = nums.size();
        st.insert( {nums[0],1} );
        mp[nums[0]] = 1;
        for( int i=1; i<size; ++i ){
            auto mp_ret = mp.insert({nums[i],0});
            auto times = mp[nums[i]];
            auto st_ret = st.find( {nums[i], times } );
            if( st_ret != st.end() ){
                st.erase( st_ret );
            }
            ++(mp_ret.first->second );
            ++times;
            st.insert( {nums[i], times} );
            auto it_b = st.begin();
            auto it_e = st.end();
            --it_e;
            if( it_b == it_e ){
                res = i+1;
            }
            if( it_b->second == it_e->second && it_b->second == 1){
                res = i+1;
                printf("%d\n",res );
                for( int j=0; j<=i; ++j ){
                    printf("%d ",nums[j] );
                }
                printf("\n");
            }
            else if( it_b->second != it_e->second ){
                auto temp = it_b;
                if( (++temp)->second == it_e->second && it_b->second==1){
                    res = i+1;
                    printf("%d\n",res );
                    for( int j=0; j<=i; ++j ){
                        printf("%d ",nums[j] );
                    }
                    printf("\n");
                    continue;
                }
                temp = it_e;
                if( (--temp)->second == it_b->second && it_e->second == it_b->second+1 ){
                    res = i+1;
                    printf("%d\n",res );
                    for( int j=0; j<=i; ++j ){
                        printf("%d ",nums[j] );
                    }
                    printf("\n");
                    continue;
                }
            }
                        
        }
        return res;
    }
private:
    static bool cmp( const pair<int,int> &a, const pair<int,int> &b ){
        return a.second == b.second ? a.first<b.first:  a.second<b.second;
    }
};

int main(){
    Solution sl;
    vector<int> vec{1,1,1,2,2,2};
    auto res = sl.maxEqualFreq( vec );
}