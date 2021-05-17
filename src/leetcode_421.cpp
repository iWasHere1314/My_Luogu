#define MY

#include<bits/stdc++.h>
using namespace std;
class tree{
public:
    tree( vector<int>& nums ){
        #ifdef MY
            auto debug_temp = nums.size();
        #endif
        for( auto &i: nums ){
            insert( this, i, 30 );
        }
    }
    tree() = default;
    
    ~tree(){
        delete zero;
        delete one;
    };

    bool find( int val, int cur_bit_num, int tar_bit_num ){
        if( cur_bit_num < tar_bit_num ){
            return true;
        }
        int bit_val = ( val>>cur_bit_num ) & 1;
        #ifdef MY
            printf( "find: val=%d, cur_bit_num=%d, tar_bit_num=%d, ", val, cur_bit_num, tar_bit_num );
        #endif
        if( bit_val && one ){
            #ifdef MY
                printf( "\t 1\n");
            #endif
            return one->find( val, cur_bit_num-1, tar_bit_num );
        }
        else if( !bit_val && zero ){
            #ifdef MY
                printf( "\t 0\n");
            #endif
            return zero->find( val, cur_bit_num-1, tar_bit_num );
        }
        #ifdef MY
            printf( "\t failed\n");
        #endif
        return false;
    }
    void insert(  tree *obj, int val , int bit_num ){
        if( bit_num < 0 ){
            return;
        }
        int bit_val = ( val>>bit_num ) & 1;
        #ifdef MY
            printf( "insert: val=%d, bit_num=%d, ", val, bit_num );
        #endif
        tree *next;
        if( bit_val ){
            #ifdef MY
                printf( "\t 1\n");
            #endif
            if( !obj->one ){
                obj->one = new tree();
            }
            next = obj->one;
        }
        else{
            #ifdef MY
                printf( "\t 0\n");
            #endif
            if( !obj->zero ){
                obj->zero = new tree();
            }
            next = obj->zero;
        }
        insert( next, val, bit_num-1 );
    }
private:
    tree *zero=nullptr, *one=nullptr;
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        auto st = tree( nums );
        int res = 0;
        size_t sz = nums.size();
        for( int i=30; i>=0; --i ){
            for( size_t j=0; j<sz; ++j ){
                if( st.find(  (res+(1<<i) )^nums[j], 30, i )  ){
                    res += 1<<i;
                    break;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution sl;
    vector<int> vec;
    vec = {3,10,5,25,2,8};
    printf("%d\n", sl.findMaximumXOR( vec ) );
//  vec = {2,4};
//  printf("%d\n", sl.findMaximumXOR( vec ) );
    return 0;
}