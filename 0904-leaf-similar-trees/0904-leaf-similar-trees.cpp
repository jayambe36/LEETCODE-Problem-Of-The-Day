class Solution {
public:
    void getLeaves(TreeNode* root, vector<int>& leaves) {
        if (!root) return;
        if (!root->left && !root->right) {  // If it's a leaf node
            leaves.push_back(root->val);
            return;
        }
        getLeaves(root->left, leaves);
        getLeaves(root->right, leaves);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        getLeaves(root1, leaves1);
        getLeaves(root2, leaves2);
        return leaves1 == leaves2;  // Compare both sequences
    }
};
