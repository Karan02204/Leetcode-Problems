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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> answer;
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);

        if(root == NULL){
            return answer;
        }

        while(!q.empty()){
            int size = q.size();
            vector<int> temp;

            for(int i=0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();
                temp.push_back(curr->val);

                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }

            result.push_back(temp);
        }

        for(int i=0;i<result.size();i++){
            answer.push_back(result[i].back());
        }

        return answer;
    }
};