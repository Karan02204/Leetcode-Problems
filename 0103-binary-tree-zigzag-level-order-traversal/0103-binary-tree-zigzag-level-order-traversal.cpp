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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        queue<TreeNode*> q;
        q.push(root);

        if(root == NULL) return answer;

        while(!q.empty()){
            vector<int> temp;
            int size = q.size();

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
            answer.push_back(temp);
        }
        for(int i=0;i<answer.size();i++){
            if(i%2!=0){
                reverse(answer[i].begin(),answer[i].end());
            }
        }

        return answer;
    }
};