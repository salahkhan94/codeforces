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
    vector<vector<int>> levelOrder(TreeNode* root){
        int parctr=0, childctr=0;
        if(root==NULL) return ans;
        else {
            par.push(root);
            parctr++;
        }    
        vector<int> temp;
        while (!par.empty())
        {
            TreeNode * tempnode = par.front();
            temp.push_back(tempnode->val);
            par.pop();
            parctr--;
            if(tempnode->left) {
                par.push(tempnode->left);
                childctr++;
            }
            if(tempnode->right){
                par.push(tempnode->right);
                childctr++;
            }
            if(parctr==0){
                ans.push_back(temp);
                parctr = childctr;
                childctr = 0;
                temp.clear();
            }
        }
        return ans;
    }
private:
    queue<TreeNode*> par;
    vector<vector<int>> ans;
};