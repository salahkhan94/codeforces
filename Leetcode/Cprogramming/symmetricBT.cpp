#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        int parctr=0, childctr=0;
        if(root==NULL) return true;
        else {
            par.push(root);
            parctr+=1;
        }    
        deque<string> temp;

        while (!par.empty())
        {
            TreeNode * tempnode = par.front();
            if(tempnode) {
                temp.push_back(to_string(tempnode->val));
                par.push(tempnode->left);
                par.push(tempnode->right);
                childctr+=2;
            }            
            else
            {
                temp.push_back("NULL");
            }
            
            par.pop();
            parctr--;
            
            if(parctr==0){
                if(temp.size()>1)
                while(temp.size()){
                    if(temp.front() == temp.back()){
                        temp.pop_front();
                        temp.pop_back();
                    }
                    else
                    {
                        return false;
                    }       
                }
                parctr = childctr;
                childctr = 0;
                temp.clear();
            }
        }
        return true;
    }
private:
    queue<TreeNode*> par;
};
