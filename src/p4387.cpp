#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1E5 + 10;

int push_seq[MAX_N];
int pop_seq[MAX_N];
bool used[MAX_N];
int n;
int q;
int main(){
    scanf("%d", &q );
    for( int t=0; t<q; ++t ){
        scanf( "%d", &n );
        for( int i=0; i<n; ++i ){
            scanf("%d", push_seq+i );
        } 
        for( int i=0; i<n; ++i ){
            scanf("%d", pop_seq+i );
        }
        memset( used, false, (n+1)*sizeof(bool) ); 
        stack<int> stk;
        bool res = true;
        for( int i=0, j=0; i<n ; ++i ){
            int tp;
            int cur = pop_seq[i];
            if( stk.size() && (tp=stk.top()) == cur ){
                stk.pop();
            }
            else if( used[cur] ){
                res = false;
                break;
            }
            else{
                int push_cur;
                while( (push_cur = push_seq[j] ) != cur ){
                    stk.push( push_cur );
                    ++j;
                    used[push_cur] = true;
                }
                ++j;
            }
        }
        printf("%s\n", res? "Yes": "No" );
    }
    return 0;
}