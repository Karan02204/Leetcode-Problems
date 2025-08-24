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
    bool Helper(TreeNode* root , long long minVal , long long maxVal){
        if(root == NULL) return true;

        if(root->val <= minVal || root->val >= maxVal){
            return false;
        }

        return Helper(root->left , minVal , root->val) && Helper(root->right , root->val , maxVal );
    }
    bool isValidBST(TreeNode* root) {
        return Helper(root , LONG_LONG_MIN , LONG_LONG_MAX);
    }
};