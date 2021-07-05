#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string countOfAtoms(string formula) {
        stack<int> brk;
        vector<int> loc;
        vector< pair< string, int> > times;
        int s_sz = formula.size();
        for( int i=0; i<s_sz; ++i ){
            if( formula[i] == '(' ){
                brk.push( i );
            }
            else if( formula[i] == ')' ){
                int nums_len= get_num_len( i+1, formula );
                int nums = nums_len? stoi( formula.substr(i+1, nums_len) ): 1;
                i += nums_len;
                int t_sz = times.size();
                int left = brk.top();
                brk.pop();
                for( int j = t_sz-1; j>=0 && loc[j]>left; --j ){
                    times[j].second *= nums;
                }
            }
            else{
                loc.emplace_back(i);
                int atm_len = get_atm_len(i, formula );
                string atm = formula.substr( i, atm_len );
                i += atm_len;
                int nums_len = get_num_len( i, formula );
                int nums = nums_len? stoi( formula.substr(i, nums_len) ): 1;
                i += nums_len - 1;
                times.emplace_back( make_pair(atm, nums ) );
            }
        }
        map< string, int> cnt;
        for( auto &t: times ){
            auto it = cnt.emplace( t.first, 0 );
            it.first->second += t.second;
        }
        string res;
        for( auto &t: cnt ){
            res.append(  t.first );
            if( t.second > 1 ){
                res.append( to_string( t.second ) );
            }
        }
        return res;
    }
    
    int get_num_len( int start, const string &formula ){
        int s_sz = formula.size();
        int j;
        for( j=start; j<s_sz; ++j ){
            if( !isdigit(formula[j]) ){
                break;
            }
        }
        return j-start;
    }

    int get_atm_len( int start, const string &formula ){
        int s_sz = formula.size();
        int j;
        for( j=start+1; j<s_sz; ++j ){
            if( !islower(formula[j]) ){
                break; 
            }
        }
        return j-start;
    }
};

// int main(){
//     Solution sl;
//     sl.countOfAtoms( "(OH2)" );
//     // sl.countOfAtoms( "Mg(OH)2" );
//     // sl.countOfAtoms( "K4(ON(SO3)2)2" );
//     // sl.countOfAtoms( "Be32" );
// }