#include<bits/stdc++.h>
using namespace std;
void print_uint_32( uint32_t num , uint32_t size ){
    for( int i=1; i<=size; ++i ){
        printf("%u", (num & (0x1U<<(size-1))) >> (size-1) );
        if( 0 == i%4 ){
            printf(" ");
        }
        num <<= 1;
    }
    return;
} 
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        return get_reverse( n>>16 , 16, 1 ) + ( get_reverse( (n & mask[0]) , 16, 1 ) << 16 );
    }
private:
    map< pair<uint32_t,uint32_t> , uint32_t > mp;
    vector<uint32_t> mask = { 0x0000ffff, 0x000000ff, 0x0000000f, 0x000000003, 0x00000001 };
    uint32_t get_reverse( uint32_t num, uint32_t size, uint32_t depth ){
        if( mp.find({num,size}) != mp.end() ){
            return mp[{num,size}];
        }
        return mp[{num,size}] = 1==size ? num:
            get_reverse( num>>(size/2) , size/2, depth+1 ) + 
            ( get_reverse( num & mask[depth], size/2, depth+1 ) << (size/2) );
        // printf("    "); print_uint_32( num ,size );printf("\n");  
        // printf("    "); print_uint_32( mp[{num,size}] ,size);printf("\n"); 
        // return mp[{num,size}];
    }
};

int main(){
    Solution sl;
    printf( "%u\n", sl.reverseBits(43261596U) );
    printf("  "); print_uint_32( 43261596U ,32 );printf("\n");  
    printf("  ");print_uint_32(sl.reverseBits(43261596U) ,32);printf("\n");  
    printf( "%u\n", sl.reverseBits(4294967293U) );
    printf("  "); print_uint_32( 4294967293U ,32);printf("\n");  
    printf("  ");print_uint_32(sl.reverseBits(4294967293U) ,32);printf("\n"); 

    return 0;
}