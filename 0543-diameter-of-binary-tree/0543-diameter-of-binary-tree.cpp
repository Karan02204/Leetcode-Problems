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
    int Helper(TreeNode* root,int& diameter){
        if(root == NULL) return 0;

        int left = Helper(root->left,diameter);
        int right = Helper(root->right,diameter);

        diameter = max(diameter,left+right);

        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        Helper(root,diameter);

        return diameter;
    }
};