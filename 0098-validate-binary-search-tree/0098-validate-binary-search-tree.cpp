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
    void Inorder(TreeNode* root, vector<int>& arr){
        if(root == nullptr){
            return;
        }
        Inorder(root->left, arr);
        arr.push_back(root->val);
        Inorder(root->right, arr);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> res;
        Inorder(root, res);
        for(int i = 1; i < res.size(); i++){
            if(res[i] > res[i-1]) continue;
            else return false;
        }
        return true;
    }
};