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
    TreeNode* prev = NULL;
    bool ans = true;
    void Inorder(TreeNode* root){
        if(root == nullptr){
            return;
        }
        Inorder(root->left);
        if(prev == NULL) prev = root;
        else{
            if(root->val <= prev->val) ans = false;
            prev = root;
        }
        Inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        Inorder(root);
        return ans;
    }
};