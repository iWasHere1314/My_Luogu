#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int clumsy(int N) {
        char op[] = { '*', '/', '+', '-' };
        stack<int> val_stk;
        stack<char> op_stk;
        op_stk.push( '#' );
        for( int i=0, num = N ; i<N; --num, ++i ){
            val_stk.push( num );
            char op_cur = 1==num? '#' : op[i%4];
            while( get_order( op_stk.top(), op_cur ) == '>' ){
                char op_pre = op_stk.top();
                op_stk.pop();
                int num2 = val_stk.top(); 
                val_stk.pop();
                int num1 = val_stk.top();
                val_stk.pop();
                val_stk.push( calc( num1, op_pre, num2 ) );
            }
            op_stk.push( op_cur );
        }
        return val_stk.top();
    }

private:
    char op_cmp[5][5] = {
        {'>', '>', '<', '<','>' },
        {'>', '>', '<', '<','>' },
        {'>', '>', '>', '>','>' },
        {'>', '>', '>', '>','>' },
        {'<', '<', '<', '<','=' },
    };
    int get_index( char c ){
        int res;
        switch( c ){
            case '+': res = 0; break;            
            case '-': res = 1; break;
            case '*': res = 2; break;
            case '/': res = 3; break;
            case '#': res = 4; break;
            default: res = -1; break;
        }
        return res;
    }
    char get_order( char a, char b ){
        return op_cmp[ get_index(a) ][ get_index(b) ];
    }
    int calc( int num1, char op, int num2 ){
        switch( op ){
            case '+': return num1+num2;           
            case '-': return num1-num2;  
            case '*': return num1*num2;  
            case '/': return num1/num2;  
            default: return -1;
        }
    }
};
int main(){
    Solution sl;
    printf("%d\n",sl.clumsy(4) );
    printf("%d\n",sl.clumsy(10) );
    return 0;
}