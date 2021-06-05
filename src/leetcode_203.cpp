#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *temp = new ListNode(0, head );
        ListNode *cur = temp;
        ListNode *next;
        while( cur ){
            next = cur->next;
            if( next && next->val == val ){
                cur->next = next->next;
            }
            else{
                cur = next;
            }
        }
        return temp->next;
    }
};