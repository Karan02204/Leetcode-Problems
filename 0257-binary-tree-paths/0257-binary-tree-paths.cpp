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
    void Helper(vector<string>& answer,string ans,TreeNode* root){
        if(root == NULL){
            return;
        }
        
        if(!ans.empty()){
            ans+= "->";
        }

        ans = ans  + to_string(root->val);

        if(root->left == NULL && root->right == NULL){
            answer.push_back(ans);
            return;
        }

        Helper(answer,ans,root->left);
        Helper(answer,ans,root->right);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> answer;
        string ans = "";
        Helper(answer,ans,root);

        return answer;
    }
};