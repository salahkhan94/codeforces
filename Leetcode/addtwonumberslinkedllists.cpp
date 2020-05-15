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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if(l1==NULL && l2 ==NULL){
            ListNode* r;
            return r;
        }
        int val1=0, val2=0,r=0,sum=0,carry=0;
        ListNode *temp1 = l1, *temp2 = l2;
        ListNode *result = new ListNode;
        ListNode *prev = new ListNode;
        for(int i=0;;i++){
            if(temp1!=NULL){
                val1 = temp1->val;
                temp1 = temp1->next;
            }
            else {
                r|=1;
                val1=0;
            }
        
            if(temp2!=NULL){
                val2 = temp2->val;
                temp2 = temp2->next;
            }
            else {
                r|=2;
                val2=0;
            }
            if(r==3) break;
            sum = val1 +val2 + carry;
            carry = sum/10;
            sum=sum%10;
            if(i){
                ListNode *l = new ListNode(sum);
                prev->next = l;
                prev = l;
            }
            else{
                result->val = sum;
                prev = result;
            }
            
        }
        if(carry){
            ListNode *l = new ListNode(carry);
            prev->next = l;
            prev = l;
        }
        return result;
    }
};