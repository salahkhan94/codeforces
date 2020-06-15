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
        int parctr=0, childctr=0;
        if(root==NULL) return root;
        else {
            par.push(root);
            parctr++;
        }    
        while (!par.empty())
        {
            Node * tempnode = par.front();   
            cout<<tempnode->val<<endl;
            par.pop();
            parctr--;
            if(tempnode->left) {
                par.push(tempnode->left);
                par.push(tempnode->right);
                childctr+=2;
            }
            if(parctr==0){
                tempnode->next = NULL;
                parctr = childctr;
                childctr = 0;
            }
            else tempnode->next = par.front();
        }
        return root;
    }
private:
    queue<Node*> par;
};

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return NULL;
        /*if(root->left)
        {
            root->left->next = root->right;
        }
        if(root->right && root->next)
        {
            root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
        return root;*/
        Node*temp = root;
        while(root->left)
        {
            Node*p = root;
            while(p)
            {
                p->left->next = p->right;
                if(p->next)
                {
                    p->right->next = p->next->left;
                }
                p = p->next;
            }
            root=root->left;
        }
        return temp;
    }
};