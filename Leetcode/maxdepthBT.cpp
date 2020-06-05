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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> pot;
        if(!root) return pot;
        if(root->left!=NULL){
            auto l = postorderTraversal(root->left);
            pot.insert(pot.end(), l.begin(), l.end());
        }
        if(root->right!=NULL)  {
            auto r = postorderTraversal(root->right);
            pot.insert(pot.end(), r.begin(), r.end());
        }
        
        pot.push_back(root->val);
        
        return pot;      
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        
    }
};