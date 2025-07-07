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
    void Helper(vector<int>& ans, TreeNode* root){
        if(root==NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->val);
        }
        Helper(ans,root->left);
        Helper(ans,root->right);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1;
        vector<int> ans2;

        Helper(ans1,root1);
        Helper(ans2,root2);

        return ans1 == ans2;
    }
};