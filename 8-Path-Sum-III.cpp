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
    int incl_node(TreeNode* node, int sum){
        if(node==nullptr) return 0;
        int res = 0;
        if(node->val == sum) res++;
        
        res +=incl_node(node->left, sum-node->val);
        res +=incl_node(node->right, sum-node->val);     
        return res;    
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if(root==nullptr) return 0;
        return pathSum(root->left, sum) + incl_node(root,sum) + pathSum(root->right, sum);
    }
};