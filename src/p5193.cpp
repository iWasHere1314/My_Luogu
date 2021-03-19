#include <bits/stdc++.h>
using namespace std;
const int scale = 100010;
int par[scale];
int height[scale];
int x_loc[scale];
int y_loc[scale];
int n;
int r;
int res;

void init()
{
    for (int i = 0; i < n; ++i)
    {
        par[i] = i;
        height[i] = 0;
    }
}

int my_find(int i)
{
    if (par[i] == i)
    {
        return i;
    }
    return par[i] = my_find(par[i]);
}

void unite(int i, int j)
{
    i = my_find(i);
    j = my_find(j);
    if (i == j)
        return;
    if (height[i] < height[j])
    {
        par[i] = j;
    }
    else
    {
        par[j] = i;
        if (height[i] == height[j])
        {
            ++height[i];
        }
    }
}
bool is_connected(int i, int j)
{
    return my_find(i) == my_find(j);
}

bool in_area(int i, int j)
{
    int dx = abs(x_loc[i] - x_loc[j]);
    int dy = abs(y_loc[i] - y_loc[j]);
    return dx + dy <= r;
}
int main()
{
    scanf("%d %d", &n, &r);
    res = n;
    init();
    vector<pair<int, int>> loc_vec(2 * n);
    for (int i = 0; i < n; ++i)
    {
        int x;
        int y;
        scanf("%d %d", &x, &y);
        x_loc[i] = x;
        y_loc[i] = y;
        loc_vec[i] = make_pair(x + y, i);
        loc_vec[i + n] = make_pair(x + r + y + 1 , i - n);
    }
    sort(loc_vec.begin(), loc_vec.end());
    set<pair<int, int>> boom_area;
    for (int i = 0; i < 2 * n; ++i)
    {
        auto id = loc_vec[i].second;
        if (id >= 0)
        {
            auto it = boom_area.lower_bound(make_pair(  y_loc[id]-x_loc[id], id));
            if( it != boom_area.end() && in_area( id, it->second ) ){
                if( !is_connected( id, it->second ) ){
                    --res;
                }
                unite( id, it->second );
            }
            if( it != boom_area.begin() && in_area( id, (--it)->second ) ){
                if( !is_connected( id, it->second ) ){
                    --res;
                }
                unite( id, it->second );
            }
            boom_area.insert(make_pair(y_loc[id]-x_loc[id], id));
        }
        else
        {
            boom_area.erase(make_pair(y_loc[id+n]-x_loc[id+n], id+n));
        }
    }

    printf("%d\n", res);

    return 0;
}
/*

13 3
0 0
1 0
2 0
3 0
4 0
5 0
6 0
3 1
3 2
3 3
3 -1
3 -2
3 -3

*/