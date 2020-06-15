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

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map <int,int> nodes;
        int index = postorder.size()-1;
        for(int i=0; i < inorder.size(); i++)
        {
            nodes[inorder[i]] = i;
        }
        
        return buildTreeUtil(inorder, postorder,index,0,inorder.size()-1, nodes);
        
    }
    
    TreeNode* buildTreeUtil(vector<int>& inorder, vector<int>& postorder, int &index, int inStart, int endStart, unordered_map <int,int> &nodes) { 
        if(index<0 || inStart>endStart)
            return NULL;
        
        TreeNode* root = new TreeNode(postorder[index]);
        int pos = nodes[postorder[index]];
        index--;
        root->right = buildTreeUtil(inorder, postorder,index, pos+1, endStart,nodes);
        root->left = buildTreeUtil(inorder, postorder, index, inStart,pos-1,nodes);
        
        return root;
    }
};

class Solution {
public:
    unordered_map<int,int> M;
    int pre;
    TreeNode* util(vector<int>& preorder, vector<int>& inorder,int st,int end)
    {
        if(st>end)
            return NULL;
        TreeNode* root=new TreeNode(preorder[pre--]);
        
        if(st==end)
            return root;
        int ind=M[root->val];
        
        root->right=util(preorder,inorder,ind+1,end);
        root->left=util(preorder,inorder,st,ind-1);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& preorder) 
    {
        int n=preorder.size();
        for(int i=0;i<n;i++)
            M[inorder[i]]=i;
        pre=n-1;
        return util(preorder,inorder,0,n-1);
    }
};

