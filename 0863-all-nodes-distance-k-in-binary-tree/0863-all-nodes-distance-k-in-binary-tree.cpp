/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track) {
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            
            if (current->left) {
                parent_track[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track; // node -> parent
        markParents(root, parent_track);
        
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        
        q.push(target);
        visited[target] = true;
        int current_level = 0;
        
        while (!q.empty()) {
            int size = q.size();
            
            if (current_level++ == k) break;
            
            for (int i = 0; i < size; ++i) {
                TreeNode* current = q.front();
                q.pop();
                
                if (current->left && !visited[current->left]) {
                    visited[current->left] = true;
                    q.push(current->left);
                }
                
                if (current->right && !visited[current->right]) {
                    visited[current->right] = true;
                    q.push(current->right);
                }
                
                if (parent_track.count(current) && !visited[parent_track[current]]) {
                    visited[parent_track[current]] = true;
                    q.push(parent_track[current]);
                }
            }
        }
        
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }
        
        return result;
    }
};