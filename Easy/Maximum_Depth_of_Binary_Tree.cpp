// https://leetcode.com/problems/maximum-depth-of-binary-tree/

class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        // base cases
        if(root == nullptr) return 0;
        
        // recursive cases
        int depthLeft = maxDepth(root->left);
        int depthRight = maxDepth(root->right);
        
        return max(depthLeft, depthRight) + 1;
    }
};
