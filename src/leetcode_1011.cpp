#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int sum = accumulate( weights.begin(), weights.end(), 0 );
        int left = 0, right = sum, mid;
        while( left + 1 < right ){
            mid = ( left + right ) >> 1;
            if( judge( mid , D, weights ) ){
                right = mid;
            }
            else{
                left = mid;
            }
        }
        return right;
    }
private:
    bool judge( int ld_ab, int D, vector<int>& weights ){
        int res=1;
        int sum=0;
        for( auto &i: weights ){
            if( i > ld_ab ){
                return false;
            } 
            else if( sum + i > ld_ab ){
                ++res;
                sum = i;
            }
            else{
                sum += i;
            }
        }
        return res<=D;
    }
};
int main(){
    // Solution sl;
    // vector<int> vec;
    // vec = {1,2,3,4,5,6,7,8,9,10};
    // printf( "%d\n", sl.shipWithinDays(vec, 5 ) );
    // vec = {3,2,2,4,1,4};
    // printf( "%d\n", sl.shipWithinDays(vec, 3 ) );
    // vec = {1,2,3,1,1};
    // printf( "%d\n", sl.shipWithinDays(vec, 4 ) );
    srand( time(NULL) );
    printf("[");
    for( int i=0; i<(int)5E4; ++i ){
        printf("%d",random()%500 + 1);
        if( i != (int)5E4-1 ){
            printf(",");
        }
    }
    printf("]\n");
    printf("%d\n", random()%500 + 1 );
    return 0;
}