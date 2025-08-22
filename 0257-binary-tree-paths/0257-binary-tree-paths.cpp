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
    void Helper(TreeNode* root , string ans , vector<string>& answer){
        if(root == NULL) return;

        if(!ans.empty()){
            ans += "->";
        }

        ans = ans + to_string(root->val);

        if(root->left == NULL && root->right == NULL){
            answer.push_back(ans);
            return;
        }

        Helper(root->left , ans, answer);
        Helper(root->right , ans, answer);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> answer;
        string ans = "";
        Helper(root, ans , answer);

        return answer;
    }
};