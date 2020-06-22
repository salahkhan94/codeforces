
#include <bits/stdc++.h>

using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        Node* t = root;
        Node* temp;
        while(t){
            Node* c = NULL;
            while (t)
            {
                if(t->left){
                    c = t->left;
                    temp = c;
                    if(t->right) {
                        temp->next = t->right;
                        temp = temp->next;
                    }
                    t = t->next;
                    break;
                }
                if(t->right){
                    c = t->right;
                    temp = c;
                    t = t->next;
                    break;
                }
                t = t->next;
            }
            while (t)
            {
                if(t->left){
                    temp->next = t->left;
                    temp = temp->next;
                }
                if(t->right){
                    temp->next = t->right;
                    temp = temp->next;
                }
                t = t->next;
            }
            t = c;
        }
        return root;
    }
};
