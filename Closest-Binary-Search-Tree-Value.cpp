class Solution{
public :
    int closestValue(TreeNode* root,double target){
        if(root->val > target && root->left){
            int l = closestValue(root->left, target);
            if(abs(l-target) < abs(root->val - target)) return l;
            return root->val;
        }
        if(root->val < target && root->right){
            int r = closestValue(root->right, target);
            if(abs(r-target) < abs(root->val - target)) return r;
            return root->val;
        }
        return root->val;
    }
}