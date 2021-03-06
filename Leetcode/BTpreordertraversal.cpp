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
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> pot;
        if(root!=NULL)
            pot.push_back(root->val);
        else return pot;
        auto l = preorderTraversal(root->left);
        pot.insert(pot.end(), l.begin(), l.end());
       
        auto r = preorderTraversal(root->right);
        pot.insert(pot.end(), r.begin(), r.end());
        
        return pot;        
    }

};