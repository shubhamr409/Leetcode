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
private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;

private:
    void inorder(TreeNode* node){
        if(node == NULL) return;
        inorder(node->left);
        if(prev != NULL && (node->val < prev-> val)){
            if(first == NULL){
                first = prev;
                middle = node;
            }
            else last = node;
        }
        prev = node;
        inorder(node->right);
    }

public:
    void recoverTree(TreeNode* root) {
        first = prev = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
    }
};