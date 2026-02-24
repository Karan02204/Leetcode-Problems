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
    vector<int> inorderTraversal(TreeNode* root) {
        //morris inorder traversal
        vector<int> result;
        if(!root) return result;
        TreeNode* currNode = root;
        
        while(currNode!=NULL){
            if(currNode->left == NULL){
                result.push_back(currNode->val);
                currNode = currNode->right;
            } else{
                TreeNode* prev = currNode->left;
                while(prev->right!=NULL && prev->right!=currNode){
                    prev = prev->right;
                }

                if(prev->right == NULL){
                    prev->right = currNode;
                    currNode = currNode->left;
                } else if (prev->right == currNode){
                    prev->right = NULL;
                    result.push_back(currNode->val);
                    currNode = currNode->right;
                }
            }
        }

        return result;
    }
};