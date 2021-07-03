#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cnt;
        for( auto i: s ){
            auto t = cnt.emplace( i, 0 );
            ++(t.first->second);
        }
        auto cmp = [&]( const char &a, const char &b )->bool{
            return cnt[a]==cnt[b]? a>b: cnt[a]>cnt[b];
        };
        sort( s.begin(), s.end(), cmp );
        return s;
    }
};

int main(){
    Solution sl;
    sl.frequencySort("bbaA");
}
