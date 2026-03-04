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
public:
    void markParent(TreeNode* root , unordered_map<TreeNode* , TreeNode*>& parent_track){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            for(int i=0;i<size;i++){
                auto node = q.front();
                q.pop();

                if(node->left){
                    parent_track[node->left] = node;
                    q.push(node->left);
                }
                if(node->right){
                    parent_track[node->right] = node;
                    q.push(node->right);
                }
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*> parent_track;
        markParent(root , parent_track);

        queue<TreeNode*> q;
        q.push(target);

        unordered_map<TreeNode* , bool> visited;
        visited[target] = true;
        int level = 0;

        while(!q.empty()){
            int size = q.size();

            if(level == k) break;
            level++;

            for(int i = 0;i<size;i++){
                TreeNode* current = q.front();
                q.pop();

                if(current->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left] = true;
                }

                if(current->right && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right] = true;
                }

                if(parent_track[current] && !visited[parent_track[current]]){
                    q.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }

        }

        vector<int> ans;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            ans.push_back(node->val);
        }

        return ans;
    }
};