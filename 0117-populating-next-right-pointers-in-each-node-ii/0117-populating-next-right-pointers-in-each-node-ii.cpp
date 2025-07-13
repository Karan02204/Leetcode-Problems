/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;

        Node* nextChild = NULL;
        Node* temp = root->next;

        while(temp){
            if(temp->left){
                nextChild = temp->left;
                break;
            } else if(temp->right){
                nextChild = temp->right;
                break;
            }

            temp = temp->next;
        }

        if(root->left && root->right){
            root->left->next = root->right;
            root->right->next = nextChild;
        } else if(root->left){
            root->left->next = nextChild;
        } else if(root->right){
            root->right->next = nextChild;
        }

        connect(root->right);
        connect(root->left);

        return root;
    }
};