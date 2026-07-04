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
vector<int> temp;
    void inOrder(TreeNode* root){
        if(root == NULL) return;
        inOrder(root->left);
        temp.push_back(root->val);
        inOrder(root->right);
        return;
    }
    bool findTarget(TreeNode* root, int k) {
        inOrder(root);
        int n = temp.size();
        int i = 0, j = n-1;
        while(i < j){
            int sum = temp[i] + temp[j];
            if (sum == k) return true;
            if (sum < k) i++;
            else if(sum > k) j--;
        }
        return false;
    }
};