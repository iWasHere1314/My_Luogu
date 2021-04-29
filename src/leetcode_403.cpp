#include<bits/stdc++.h>
using  namespace std;
class Solution {
public:
    bool canCross(vector<int>& stones) {
        size_t sz = stones.size();
        unordered_set<size_t> from[sz];
        if( stones[1] == 1 ){
            from[1].insert(0);
        }
        for( size_t i=1; i<sz; ++i ){
            for( auto &j: from[i] ){
                int dis = stones[i] - stones[j];
                int start = stones[i] + dis - 1;
                int end = start + 2;
                auto it = lower_bound( stones.begin(), stones.end(), start );
                while( it != stones.end() && *it<=end ){
                    from[it-stones.begin()].insert( i );
                    //printf("\tfrom %d to %d to %d, currently skip %d\n", stones[j], stones[i], *it, *it-stones[i] );
                    ++it;
                }
            }
        }
        return !from[sz-1].empty();
    }
};
int main(){
    // Solution sl;
    // vector<int> vec;
    // vec = {0,1,2,3,4,8,9,11};
    // printf("%d\n", sl.canCross(vec) );
    // vec = {0,1,3,5,6,8,12,17};
    // printf("%d\n", sl.canCross(vec) );
    // vec = {0,1};
    // printf("%d\n", sl.canCross(vec) );
    srand( time(NULL) );
    printf("[");
    set<int> res;
    res.insert(0);
    res.insert(1);
    for( int i=0; i<1998; ++i ){
        int temp;
        auto pre = res.end();
        --pre;
        temp = *pre + (int)random()%(5);
        res.insert(temp);
    }
    int i=0;
    for(  auto it = res.begin() ; it != res.end(); ++it, ++i ){
        printf("%d", *it );
        if( i != 1999 ){
            printf(",");
        }
    }
    printf("]\n");
    return 0;
}