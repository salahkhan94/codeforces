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
    unordered_map<int , int> inord;
    int pre=0;
    TreeNode* util(vector<int>& preorder, vector<int>& inorder, int st,int en) {
        TreeNode * root = new TreeNode();
        if(st<=en){
            root->val = preorder[pre++];
        }
        else {
            root = NULL;
            return root;
        }
        if(st < en){
            auto pos = inord[root->val];
            root->left = util(preorder, inorder, st, pos-1);
            root->right = util(preorder, inorder, pos+1, en);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i=0;i<inorder.size();i++){
            inord[inorder[i]] = i;
        }

        return util(preorder, inorder, 0, inorder.size()-1);
    }
};

