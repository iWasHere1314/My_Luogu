#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        size_t sz = k;
        unordered_map<string, int> word_cnt;
        for( auto &str: words ){
            auto it = word_cnt.emplace( str, 0 );
            ++it.first->second;
        }
        auto cmp = [ & ]( const pair<string, int> &a, const pair<string, int> &b )->bool{
            return word_cnt[a.first] == word_cnt[b.first]? a.first<b.first: word_cnt[a.first]>word_cnt[b.first];
        };
        priority_queue< pair<string, int>, deque< pair<string, int> >, decltype(cmp) > q( cmp );

        for( auto &i: word_cnt ){
            q.push( i );
            if( q.size() > sz ){
                q.pop();
            }
        }
        vector<string> res(sz);
        for( size_t i=sz-1; i>0 ; --i ){
            auto temp = q.top();
            q.pop();
            res[i] = temp.first;
        }
        auto temp = q.top();
        q.pop();
        res[0] = temp.first;
        return res;
    }
};
int main(){
    Solution sl;
    vector<string> vec = {"i", "love", "leetcode", "i", "love", "coding"};
    sl.topKFrequent( vec, 2 );
}