#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> cnt;
        int sz = answers.size();
        int res=0;
        for( int i=0; i<sz; ++i ){
            auto it = cnt.find( answers[i] );
            if( it == cnt.end() || 0 == it->second){
                cnt[answers[i]] = answers[i];
                res += answers[i] + 1;
            }
            else if( it->second ){
                --(it->second);
            }
        }
        return res;
    }
};
int main(){
    Solution sl;
    vector<int> vec;
    vec={1, 1, 2};
    printf("%d\n", sl.numRabbits( vec ) ); 
    vec={10, 10, 10};
    printf("%d\n", sl.numRabbits( vec ) );
    vec={2, 2, 2, 2};
    printf("%d\n", sl.numRabbits( vec ) );  
}