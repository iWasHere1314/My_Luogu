#include<bits/stdc++.h>
using namespace std;
class Trie {
public:
    /** Initialize your data structure here. */
    Trie( char v='\0' ): val(v), is_end(false), child({}) {};
    
    /** Inserts a word into the trie. */
    void insert(const string& word) {
        auto cur = this;
        size_t index = 0;
        size_t sz = word.size();
        while( index<sz && cur->child.size() ){
            size_t sz1 = cur->child.size();
            bool flag = false;
            for( size_t i=0; i<sz1; ++i ){
                if( word[index]== cur->child[i]->val ){
                    ++index;
                    cur = cur->child[i];
                    flag = true;
                    break;
                }
            }
            if( !flag ){
                break;
            }
        }
        while( index<sz ){
            auto temp = new Trie(word[index]);
            cur->child.push_back(temp);
            ++index;
            cur = temp;
        }
        cur->is_end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(const string& word) {
        auto cur = this;
        size_t index = 0;
        size_t sz = word.size();
        while( index<sz && cur->child.size() ){
            size_t sz1 = cur->child.size();
            bool flag = false;
            for( size_t i=0; i<sz1; ++i ){
                if( word[index] == cur->child[i]->val ){
                    ++index;
                    cur = cur->child[i];
                    flag = true;
                    break;
                }
            }
            if( !flag ){
                return false;
            }
        }
        return index==sz && cur->is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string& prefix) {
                auto cur = this;
        size_t index = 0;
        size_t sz = prefix.size();
        while( index<sz && cur->child.size() ){
            size_t sz1 = cur->child.size();
            bool flag = false;
            for( size_t i=0; i<sz1; ++i ){
                if( prefix[index]== cur->child[i]->val ){
                    ++index;
                    cur = cur->child[i];
                    flag = true;
                    break;
                }
            }
            if( !flag ){
                return false;
            }
        }
        return index==sz;
    }
private:
    char val;
    bool is_end;
    vector<Trie*> child;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */