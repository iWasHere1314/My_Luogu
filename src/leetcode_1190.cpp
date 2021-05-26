#define MY_DEBUG

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseParentheses(string s) {
        size_t sz = s.size();
        size_t real_sz=sz;
        /* count */
        unordered_map<size_t, size_t> bk;
        stack<size_t> l;
        for( size_t i=0; i<sz; ++i ){
            if( s[i] == '(' ){
                --real_sz;
                l.push(i);
            }
            else if( s[i] == ')' ){
                --real_sz;
                size_t t = l.top();
                l.pop();
                bk[i]=bk[t] = i-t+1;
            }
        }
        bool forward = true;
        string pre_res( sz, '#' );
        for( size_t i=0, j=0; i<sz; ++i ){
            if( s[i] == '(' ){
                j += forward? bk[i]-1: -(bk[i]-1);
                forward = !forward;
                pre_res[j] = '(';
                j += forward? 1: -1;
            }   
            else if( s[i] == ')' ){
                pre_res[j] = ')';
                j += forward? -bk[i]: bk[i];
                forward = !forward;
            } 
            else{
                pre_res[j] = s[i];
                j += forward? 1: -1;
            }
        }

        string res( real_sz, '#' );
        for( size_t i=0, j=0; i<sz; ++i ){
            char ch = pre_res[i];
            if(  ch != '(' && ch != ')' ){
                res[j++] = ch;
            }
        }
        return res;
    }
};
#ifdef MY_DEBUG
int main(){
    Solution sl;
    sl.reverseParentheses( "(a(bcd)(e(fgh))i)" );
}
#endif