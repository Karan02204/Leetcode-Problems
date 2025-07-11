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
    void Helper(TreeNode* root , vector<int>& answer){
        if(root == NULL){
            return;
        }

        Helper(root->left,answer);
        answer.push_back(root->val);
        Helper(root->right,answer);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> answer;
        Helper(root,answer);

        return answer[k-1];
    }
};