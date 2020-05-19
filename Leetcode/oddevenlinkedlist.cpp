#include <bits/stdc++.h>
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
    ListNode* oddEvenList(ListNode* head) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* even=head->next;
        ListNode* i = head;
        ListNode* j = even;
        while(i->next!=nullptr && j->next!=nullptr){
            i->next = j->next;
            i = i->next;
            j->next = i->next;
            j = j->next;
        }
        i->next = even;
        return head;
    }
};