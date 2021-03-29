#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int size = arr.size();
        vector<int> load(size, 0);
        stack<pair<int, long long>> inc;
        long long res = 0;
        for (int i = 0; i < size; ++i)
        {
            if (inc.empty() || inc.top().second < arr[i])
            {
                inc.emplace(i, arr[i]);
            }
            else
            {
                pair<int, int> temp;
                while (inc.size() && (temp = inc.top()).second >= arr[i])
                {
                    inc.pop();
                    int len = i - temp.first;
                    long long addition = 0;
                    if ( temp.first >= 0 && load[temp.first] )
                    {
                        load[i] += load[temp.first];
                        addition = ( (len - 1) * temp.second + arr[i] ) *load[temp.first] ;
                    }
                    load[i] += 1; //size-1-(i+1)+1
                    res += len * temp.second + arr[i] + addition;
                }
                inc.emplace(i, arr[i]);
            }
        }
        int end = size - 1;
        while (inc.size())
        {
            auto temp = inc.top();
            inc.pop();
            long long len = end - temp.first + 1;
            res += temp.second*(len-1)*(temp.first == end ? 0: load[temp.first]);
            res += len * temp.second;
        }
        return (int)(res % 1000000007);
    }
};

int main()
{
    Solution sl;
    vector<int> vec = {3, 1, 2, 4};
    printf("%d\n", sl.sumSubarrayMins(vec));
    vec = {11, 81, 94, 43, 3};
    printf("%d\n", sl.sumSubarrayMins(vec));
    vec = {3, 1, 2, 4, 5, 1, 6};
    printf("%d\n", sl.sumSubarrayMins(vec));
    vec = {64,85,25,74,12};
    printf("%d\n", sl.sumSubarrayMins(vec));
    vec = {72,40,83};
    printf("%d\n", sl.sumSubarrayMins(vec));

    return 0;
}

/* 
int lg[(int)(3*10E4+10)];
int dp[(int)(3*10E4+10)][20];
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int size = arr.size();
        for( int i=2; i<=size; ++i ){
            lg[i] = lg[i/2] + 1;
        }
        for( int i=0; i<size; ++i ){
            dp[i][0] = arr[i];
        }
        for( int i=1, exp=1; exp*2<=size; ++i){
            int len = exp*2;
            for( int j=0; j+exp*2<=size; ++j ){
                dp[j][i] = min(dp[j][i-1], dp[j+exp][i-1] );
            }
            exp = len;
        }
        auto f = []( int l, int r )->int{
            int exp = lg[r-l+1];
            return min( dp[l][exp], dp[r-(1<<exp)+1][exp] );
        };

        long long res=0;
        for( int i=0; i<size; ++i ){
            for( int j=i; j<size; ++j ){
                res = res+f(i,j);
            }
        }
        return (int)(res%1000000007);
    }
};
 */