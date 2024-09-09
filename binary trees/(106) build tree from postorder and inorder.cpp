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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int start, int end, unordered_map<int, int> &mp, int &postIndex){

        if(start > end) return NULL;

        TreeNode* root = new TreeNode(postorder[postIndex--]);
        if(start == end) return root;

        int index = mp[root->val];

        root->right = build(inorder, postorder, index+1, end, mp, postIndex);
        root->left = build(inorder, postorder, start, index-1, mp, postIndex);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;

        int n = inorder.size();
        int postIndex = n-1;
        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }
        
        TreeNode* root = build(inorder, postorder, 0, n-1, mp, postIndex);

        return root;
    }
    
};
