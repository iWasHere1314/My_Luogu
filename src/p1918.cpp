#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 10E5+10;
const int MAX_Q = 10E5+10;
pair<int, int> bottles[MAX_N];
pair<int, int> query[MAX_Q];
map<int, int> res;

bool p_s_less(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

int main()
{
    int n, q;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int num;
        scanf("%d", &num);
        bottles[i] = make_pair(i, num);
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; ++i)
    {
        int num;
        scanf("%d", &num);
        query[i] = make_pair(i, num);
        res[i] = 0;
    }
    sort(bottles + 1, bottles + n + 1, p_s_less);
    sort(query + 1, query + q + 1, p_s_less);
    int i = 1, j = 1;
    while (i <= q && j <= n)
    {
        if (query[i].second == bottles[j].second)
        {
            res[query[i].first] = bottles[j].first;
            ++i;
        }
        else if (query[i].second < bottles[j].second)
        {
            ++i;
        }
        else
        {
            ++j;
        }
    }
    for (i = 1; i <= q; ++i)
    {
        printf("%d\n", res[i]);
    }

    return 0;
}