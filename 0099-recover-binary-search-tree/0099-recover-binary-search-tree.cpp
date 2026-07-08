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
#define Node TreeNode
#define null NULL

class Solution {
public:
    Node* prev = null;
    Node* g1first = null;
    Node* g1second = null;
    Node* g2first= null;
    Node* g2second = null;
    int galat = 0;
    void Inorder(TreeNode* root){
        if(root == nullptr){
            return;
        }
        Inorder(root->left);
        if(prev == null) prev = root;
        else{
            if(root->val < prev->val){
                if(galat == 0){
                    g1first = prev;
                    g1second = root;
                    galat++;
                }
                else{
                    g2first = prev;
                    g2second = root;
                    galat++;
                }
            }
            prev = root;
        }
        Inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        Inorder(root);
        if(galat == 1) swap(g1first->val, g1second->val);
        else swap(g1first->val, g2second->val);
        return;
    }
};