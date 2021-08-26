// https://leetcode.com/problems/binary-tree-postorder-traversal/

class Solution {
public:
    
    // preorder:    action, left, right
    // inorder:     left, action, right
    // postorder:   left, right, action    
    
    void postOrderRecursive(TreeNode* root, vector<int> & store)
    {
        // base case
        if(root == nullptr) return;
        
        // recursive case
        postOrderRecursive(root->left, store);
        postOrderRecursive(root->right, store);
        store.push_back(root->val);        
    }
    
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> store;
        postOrderRecursive(root, store);
        return store;
    }
};
