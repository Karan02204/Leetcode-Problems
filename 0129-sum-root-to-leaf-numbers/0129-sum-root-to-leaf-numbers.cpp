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
    void Helper(int& sum,int number,TreeNode* root){
        if(root == NULL){
            return;
        }
        
        number = number*10 + root->val;

        if(root->left == NULL && root->right == NULL){
            sum+=number;
            return;
        }

        Helper(sum,number,root->left);
        Helper(sum,number,root->right);
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        int number = 0;

        Helper(sum,number,root);

        return sum;
    }
};