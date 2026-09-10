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
int matching_nodes_count = 0;
int left_sum, left_count, right_sum, right_count;
    pair<int, int> dfs(TreeNode* node){
        if(node == NULL) return {0, 0};

        auto [left_sum, left_count] = dfs(node->left);
        auto [right_sum, right_count] = dfs(node->right);
        int curr_sum = node->val + left_sum + right_sum;
        int curr_count = 1 + left_count + right_count;

        int average = (curr_sum / curr_count);
        if(node->val == average) matching_nodes_count++;
        return {curr_sum, curr_count};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return matching_nodes_count;
    }
};