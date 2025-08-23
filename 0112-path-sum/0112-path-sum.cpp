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
    void Helper(TreeNode* root , int targetSum , int sum , bool& result){
        if(root == NULL) return;

        sum = sum + root->val;

        if(root->left == NULL && root->right == NULL){
            if(targetSum == sum) result = true;
            return;
        }

        Helper(root->left , targetSum , sum , result);
        Helper(root->right , targetSum , sum , result);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool result = false;
        Helper(root,targetSum , sum , result);

        return result;
    }
};