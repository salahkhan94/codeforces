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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p ==root || q == root) return root;
        levelOrder(root, p, q);
        auto pans = ancestors[p];
        auto qans = ancestors[q];
        auto i = pans.rbegin();
        for(;i!= pans.rend();++i){
            if(find(qans.begin(), qans.end(), *i)!= qans.end()) break;
        }
        return *i;
    }
    
    void levelOrder(TreeNode* root, TreeNode* p, TreeNode* q){
        int parctr=0, childctr=0;
        if(root==NULL) return;
        else {
            par.push(root);
            vector<TreeNode *> s;
            s.push_back(root);
            ancestors[root] = s;
            parctr++;
        }    
        bool pf = false,qf = false;
        while (!pf || !qf)
        {
            TreeNode * tempnode = par.front();
            par.pop();
            parctr--;
            if(tempnode->left) {
                auto ances = ancestors[tempnode];
                ances.push_back(tempnode->left);
                ancestors[tempnode->left] = ances;
                if(tempnode->left == p) pf = true;
                else if(tempnode->left == q) qf = true;
                par.push(tempnode->left);
                childctr++;
            }
            if(tempnode->right){
                auto ances = ancestors[tempnode];
                ances.push_back(tempnode->right);
                ancestors[tempnode->right] = ances;
                if(tempnode->right == p) pf = true;
                else if(tempnode->right == q) qf = true;
                par.push(tempnode->right);
                childctr++;
            }
            if(parctr==0){
                parctr = childctr;
                childctr = 0;
            }
        }
    }
private:
    unordered_map<TreeNode *, vector<TreeNode*> > ancestors;
    queue<TreeNode*> par;
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        tlowestCommonAncestor(root, p, q);
        return ans;
    }

    bool tlowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        bool mid = false, left = false, right = false;
        if(root == p || root == q) mid = true;

        if(root->left!=nullptr && !ans) {
            left = lowestCommonAncestor(root->left, p, q);
        }
        
        if(root->right!=nullptr && !ans) {
            right = lowestCommonAncestor(root->right, p, q);
        }

        if((mid && left) || (mid && right) || (left && right)) {
            ans = root;
        }
        return (mid || left || right);
    }

private:
    TreeNode *ans = nullptr;
};