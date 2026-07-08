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
    void Inorder(TreeNode* root, vector<TreeNode*>& arr){
        if(root == nullptr){
            return;
        }
        Inorder(root->left, arr);
        arr.push_back(root);
        Inorder(root->right, arr);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> res;
        Inorder(root, res);
        int galat = 0;
        int g1first = 0, g1second = 0, g2first= 0, g2second = 0;
        for(int i = 0; i < res.size()-1; i++){
            if(res[i]->val > res[i+1]->val){
                if(galat == 0){
                    g1first = i;
                    g1second = i+1;
                    galat++;
                }
                else{
                    g2first = i;
                    g2second = i+1;
                    galat++;
                }
            }
        }
        if(galat == 1) swap(res[g1first]->val, res[g1second]->val);
        else swap(res[g1first]->val, res[g2second]->val);
        return;
    }
};