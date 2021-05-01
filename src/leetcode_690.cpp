#include<bits/stdc++.h>
using namespace std;
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};


class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        return dfs( employees, get_loc( employees, id ) );
    }
private:
    int dfs( vector<Employee*> &employees, size_t loc ){
        auto temp = employees[loc];
        auto& sub = temp->subordinates;
        int res = temp->importance;
        size_t sz = sub.size();
        for( size_t i=0; i<sz; ++i ){
            res += dfs( employees, get_loc( employees, sub[i] ) );
        }
        return res;
    }
    size_t get_loc( vector<Employee*> &employees, int id ){
        size_t sz = employees.size();
        for( size_t i=0; i<sz; ++i ){
            if( employees[i]->id == id ){
                return i;
            }
        }
        return 0;
    }
};