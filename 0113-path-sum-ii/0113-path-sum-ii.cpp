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
    void Helper(TreeNode* root , int targetSum, vector<int> answer , vector<vector<int>>& result, int sum){
        if(root == NULL){
            return;
        }

        sum += root->val;
        answer.push_back(root->val);

        if(root->left == NULL && root->right == NULL && sum == targetSum){
            result.push_back(answer);
            return;
        }

        Helper(root->left , targetSum , answer ,result , sum);
        Helper(root->right , targetSum , answer ,result , sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> answer;
        int sum = 0;
        Helper(root , targetSum , answer , result ,sum);

        return result;
    }
};