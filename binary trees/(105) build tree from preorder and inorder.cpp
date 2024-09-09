/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int start, int end, map<int, int> mp, int preIndex){
        if(start>end) return NULL;

        TreeNode* root=new TreeNode(preorder[preIndex]);
        int inIndex = mp[root->val];

        root->left=build(preorder, inorder, start, inIndex-1, mp, preIndex+1);
        root->right=build(preorder, inorder, inIndex+1, end, mp, preIndex +inIndex -start +1);
        // root of right subtree = (preIndex + 1) + (inIndex - start);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root= build(preorder, inorder, 0, inorder.size()-1, mp, 0);
        return root;  
    }
};


/**************
class Solution {
public:
    int rIndex=0;
    int search(vector<int>& in, int left,int right, int value){
        for(int i=left; i<=right; i++){
            if(in[i]==value){
                return i;
            }
        }
        return 0;
    }
    TreeNode* build(vector<int>& pre,vector<int>& in, int left,int right){
        if(left>right) return NULL;
        TreeNode* root=new TreeNode(pre[rIndex++]);

        int root1=search(in, left, right, root->val);
        
        root->left=build(pre, in, left, root1-1);
        root->right=build(pre, in, root1+1, right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root= build(preorder,inorder, 0, preorder.size()-1);
        return root;
    }
};
*/


/********************
// using map--------------
class Solution {
public:
    int preIndex=0;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int start, int end, unordered_map<int, int> & mp) {
        if(start > end){
            return NULL;
        }

        int value = preorder[preIndex++];
        int index = mp[value];
        TreeNode* root = new TreeNode(value);

        root->left = build(preorder, inorder, start, index-1, mp);
        root->right = build(preorder, inorder, index+1, end, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;

        int n = inorder.size();
        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }

        TreeNode* root = build(preorder, inorder, 0, n-1, mp);
        return root;
    }
};
*/
