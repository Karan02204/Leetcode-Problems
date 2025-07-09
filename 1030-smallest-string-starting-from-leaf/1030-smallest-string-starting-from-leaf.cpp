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
    void Helper(string answer, string& result, TreeNode* root){
        if(root == NULL){
            return;
        }

        answer = char(root->val + 'a')+answer;

        if(root->left == NULL && root->right == NULL){
            result = min(answer,result);
            return;
        }

        Helper(answer,result,root->left);
        Helper(answer,result,root->right);

    }
    string smallestFromLeaf(TreeNode* root) {
        string answer = "";
        string result = "~";
        Helper(answer,result,root);

        return result;
    }
};