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
    void Helper(TreeNode* root , int& sum , int number){
        if(root == NULL){
            return;
        }

        number = number*10 + root->val;
        if(root->left == NULL && root->right == NULL){
            sum+=number;
            return;
        }

        Helper(root->left , sum , number);
        Helper(root->right , sum , number);
    }
     int sumNumbers(TreeNode* root) {
        int sum = 0;
        int number = 0;

        Helper(root , sum , number);

        return sum;
    }
};