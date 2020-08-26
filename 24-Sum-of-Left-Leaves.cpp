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
    int ans = 0;
    void dfs(TreeNode* root){
        if(root == nullptr) return;
        if(root->left){
            if(root->left->left == nullptr && root->left->right == nullptr){
                ans += root->left->val;
            }
            else dfs(root->left);
        }
        if(root->right)
            dfs(root->right);
        
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr) return 0;
        dfs(root);
        return ans;
    }
};