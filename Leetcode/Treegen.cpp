#include <bits/stdc++.h>

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode * root = new TreeNode();
        if(inorder.size()) 
        {
            root->val = postorder[postorder.size()-1];
        }
        else{
            TreeNode *r= NULL;
            return r;
        } 
    
        if(postorder.size()>1){
            auto r = find(inorder.begin(), inorder.end(), root->val);
            vector<int> l_inorder(inorder.begin(), r);
            vector<int> r_inorder(r+1, inorder.end());
            int s = r - inorder.begin();
            auto t = postorder.begin() +s;
            vector<int> l_postorder(postorder.begin(), t);
            vector<int> r_postorder(t, postorder.end()-1);

            root->left = buildTree(l_inorder, l_postorder);
            root->right = buildTree(r_inorder, r_postorder);
        
        }
        return root;
    }
};